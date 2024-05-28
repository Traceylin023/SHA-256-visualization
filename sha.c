#include <stdio.h>
#include "main.h"
#include "des.h"
#include "sha.h"
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>


uint32_t * rotate(uint32_t * input, int shift){
    uint32_t a = *input >> shift;
    uint32_t b = *input << (32 - shift);
    uint32_t c = a | b ;
    return &c;
}   

uint32_t * funct0(uint32_t * n0){
    uint32_t a = rotate(*n0, 7);
    uint32_t b = rotate(*n0, 18);
    uint32_t c = *n0 >> 3;
    uint32_t acc0 = a ^ b;
    uint32_t acc1 = acc0 ^ c;
    return &acc1;
}

uint32_t * funct1(uint32_t * n0){
    uint32_t a = rotate(*n0, 17);
    uint32_t b = rotate(*n0, 9);
    uint32_t c = *n0 >> 10;
    uint32_t acc0 = a ^ b;
    uint32_t acc1 = acc0 ^ c;
    return &acc1;
}

uint32_t *pad(char *input, int chunkNum) {
    int size = chunkNum * 16;
    uint32_t output[size];
    for (int i = 0; i < size; i++) {
        output[i] = 0b0;
    }

    /*  The above section is weird because I couldn't figure out
        how to create a variable-length array but this works somehow */
        
    int blockNum = 0;
    printf("%d", strlen(input));
    for (int i = 0; i < strlen(input) + (4-(strlen(input)%4)); i++) {
        if (i/4 > blockNum) {
            blockNum++;
        }
        pbin(output[blockNum], 32);
        output[blockNum] = output[blockNum] << 8;
        pbin(output[blockNum], 32);
        if (i > strlen(input)) {
            output[blockNum] |= 0b0;
        }
        else {
            output[blockNum] |= input[i];
        }
        pbin(output[blockNum], 32);
        printf("%d", blockNum);
        printf("\n");
    }
    uint32_t one_pad = 0b1;
    uint32_t zero_pad = 0b0;
    // pbin(output[blockNum], 32);
    // output[blockNum] = output[blockNum] << 8;
    // pbin(output[blockNum], 32);
    // output[blockNum] |= one_pad;
    // pbin(output[blockNum], 32);
    uint32_t *ptr = output;
    return ptr;
}

void sha_encrypt (char *input_filename, char *output_filename) {
    uint32_t initialArray[64];  //initialize array
    int f = open(input_filename, O_RDONLY);
    FILE * fil = fopen(input_filename, O_RDONLY);
    fseek(fil, 0, SEEK_END);
    unsigned long fileLength = ftell(fil);
    int chunks = (int)(trunc(fileLength / 512)+1);

    //initialize initial 8 hash values
    uint32_t hash[8];
    char * ptr;
    hash[0] = strtol("6a09e667",ptr,16);
    hash[1] = strtol("bb67ae85",ptr,16);
    hash[2] = strtol("3c6ef372",ptr,16);
    hash[3] = strtol("a54ff53a",ptr,16);
    hash[4] = strtol("510e527f",ptr,16);
    hash[5] = strtol("9b05688c",ptr,16);
    hash[6] = strtol("1f83d9ab",ptr,16);
    hash[7] = strtol("5be0cd19",ptr,16);

    //initialize 64 constants
    uint32_t constants[64];
    constants[0] = strtol("428a2f98",ptr,16);
    constants[1] = strtol("71374491",ptr,16);
    constants[2] = strtol("b5c0fbcf",ptr,16);
    constants[3] = strtol("e9b5dba5",ptr,16);
    constants[4] = strtol("3956c25b",ptr,16);
    constants[5] = strtol("59f111f1",ptr,16);
    constants[6] = strtol("923f82a4",ptr,16);
    constants[7] = strtol("ab1c5ed5",ptr,16);
    constants[8] = strtol("d807aa98",ptr,16);
    constants[9] = strtol("12835b01",ptr,16);
    constants[10] = strtol("243185be",ptr,16);
    constants[11] = strtol("550c7dc3",ptr,16);
    constants[12] = strtol("72be5d74",ptr,16);
    constants[13] = strtol("80deb1fe",ptr,16);
    constants[14] = strtol("9bdc06a7",ptr,16);
    constants[15] = strtol("c19bf174",ptr,16);
    constants[16] = strtol("e49b69c1",ptr,16);
    constants[17] = strtol("efbe4786",ptr,16);
    constants[18] = strtol("0fc19dc6",ptr,16);
    constants[19] = strtol("240ca1cc",ptr,16);
    constants[20] = strtol("2de92c6f",ptr,16);
    constants[21] = strtol("4a7484aa",ptr,16);
    constants[22] = strtol("5cb0a9dc",ptr,16);
    constants[23] = strtol("76f988da",ptr,16);
    constants[24] = strtol("983e5152",ptr,16);
    constants[25] = strtol("a831c66d",ptr,16);
    constants[26] = strtol("b00327c8",ptr,16);
    constants[27] = strtol("bf597fc7",ptr,16);
    constants[28] = strtol("c6e00bf3",ptr,16);
    constants[29] = strtol("d5a79147",ptr,16);
    constants[30] = strtol("06ca6351",ptr,16);
    constants[31] = strtol("14292967",ptr,16);
    constants[32] = strtol("27b70a85",ptr,16);
    constants[33] = strtol("2e1b2138",ptr,16);
    constants[34] = strtol("4d2c6dfc",ptr,16);
    constants[35] = strtol("53380d13",ptr,16);
    constants[36] = strtol("650a7354",ptr,16);
    constants[37] = strtol("766a0abb",ptr,16);
    constants[38] = strtol("81c2c92e",ptr,16);
    constants[39] = strtol("92722c85",ptr,16);
    constants[40] = strtol("a2bfe8a1",ptr,16);
    constants[41] = strtol("a81a664b",ptr,16);
    constants[42] = strtol("c24b8b70",ptr,16);
    constants[43] = strtol("c76c51a3",ptr,16);
    constants[44] = strtol("d192e819",ptr,16);
    constants[45] = strtol("d6990624",ptr,16);
    constants[46] = strtol("f40e3585",ptr,16);
    constants[47] = strtol("106aa070",ptr,16);
    constants[48] = strtol("19a4c116",ptr,16);
    constants[49] = strtol("1e376c08",ptr,16);
    constants[50] = strtol("2748774c",ptr,16);
    constants[51] = strtol("34b0bcb5",ptr,16);
    constants[52] = strtol("391c0cb3",ptr,16);
    constants[53] = strtol("4ed8aa4a",ptr,16);
    constants[54] = strtol("5b9cca4f",ptr,16);
    constants[55] = strtol("682e6ff3",ptr,16);
    constants[56] = strtol("748f82ee",ptr,16);
    constants[57] = strtol("78a5636f",ptr,16);
    constants[58] = strtol("84c87814",ptr,16);
    constants[59] = strtol("8cc70208",ptr,16);
    constants[60] = strtol("90befffa",ptr,16);
    constants[61] = strtol("a4506ceb",ptr,16);
    constants[62] = strtol("bef9a3f7",ptr,16);
    constants[63] = strtol("c67178f2",ptr,16);

    uint32_t arr[64];
    for(int i = 0; i < chunks; i++){
        for(int i = 0; i < 16; i++){ // read the chunck
            read(f, arr[i], 32);
        }
        for(int i = 0; i < 47; i++){ // calculate the rest of the array
            arr[i+16] = arr[i] + *funct0(arr[i+1]) + arr[i+9] + *funct1(i+14) ;
        }
    }
}

void sha_decrypt (char *input_filename, char *output_filename) {

}
