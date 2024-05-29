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
#include <stdbool.h>


int err(int line){
    printf("line: %d\n",line);
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

uint32_t rotate(uint32_t input, int shift){
    uint32_t a = input >> shift;
    uint32_t b = input << (32 - shift);
    uint32_t c = a | b ;
    return &c;
}   

uint32_t funct0(uint32_t n0){
    uint32_t a = rotate(n0, 7);
    uint32_t b = rotate(n0, 18);
    uint32_t c = n0 >> 3;
    uint32_t acc0 = a ^ b;
    uint32_t acc1 = acc0 ^ c;
    return &acc1;
}

uint32_t funct1(uint32_t n0){
    uint32_t a = rotate(n0, 17);
    uint32_t b = rotate(n0, 9);
    uint32_t c = n0 >> 10;
    uint32_t acc0 = a ^ b;
    uint32_t acc1 = acc0 ^ c;
    return &acc1;
}

uint32_t *pad(char *input, int chunkNum) {
    int size = chunkNum * 16;
    uint32_t * output = (uint32_t*)malloc(size*32);
    for (int i = 0; i < size; i++) {
        output[i] = 0b0;
    }
    bool onepadded = false;
    int blockNum = 0;
    for (int i = 0; i < strlen(input) + (4-(strlen(input)%4)); i++) {
        if (i/4 > blockNum) {
            blockNum++;
        }
        output[blockNum] = output[blockNum] << 8;
        if (i >= strlen(input)) {
            if (!onepadded) {
                onepadded = !onepadded;
                output[blockNum] |= 128;
            }
            else {
                output[blockNum] |= 0b0;
            }
        }
        else {
            output[blockNum] |= input[i];
        }
    }
    blockNum = size-2;
    uint64_t plainLength = strlen(input)*8;
    output[blockNum] = (plainLength & 0xFFFFFFFF00000000) >> 32;
    output[blockNum+1] = plainLength & 0x00000000FFFFFFFF; 
    uint32_t *ptr = output;
    return ptr;
}

void sha_encrypt (char *input_filename, char *output_filename) {
    uint32_t initialArray[64];  //initialize array
    int f = open(input_filename, O_RDONLY);
    FILE * fil = fopen(input_filename, "r");
    fseek(fil, 0, SEEK_END);
    unsigned long fileLength = ftell(fil);
    printf("size: %ld\n", fileLength);
    int chunks = (int)(trunc(fileLength / 512)+1);

    uint32_t * arr = (uint32_t*)malloc(256);
    // char * arr = malloc(256);
    char array[256];
    for(int i = 0; i < chunks; i++){
        // for(int i = 0; i < 16; i++){ // read the chonckkk
        //     for(int j = 0; j < 4 ;j++){
        //         int asdf = read(f, arr, 1); // err(__LINE__);
        //     }
        //     // printf("arr[%d]: %ld\n",i, arr[i]);
        //     // pbin(arr[i], 32);
        //     // printf("[%d]\n",i);
        // }
        read(f,arr,64);// err(__LINE__);
        
        // pbin(*arr, 64*32);  
        // for(int a = 0; a < 256; a++){
            // pbin(arr, 256);
        // }
        for(int i = 0; i < 47; i++){ // calculate the rest of the array
            // arr[i+16] = arr[i] + *funct0(&arr[i+1]) + arr[i+9] + *funct1(&arr[i+14]);
            // funct
        }
    }
    strcpy(array,arr);
    for(int i = 0; i < 64; i++){
        // printf("");
        pbin(array[i], 8);
    }
    // printf(("input: %s\n"), arr);
    // printf("%d\n", sizeof(arr));
    // int output = open(output_filename, O_CREAT | O_WRONLY, 0644);
    // int er = write(output, arr,64);// err(__LINE__);
}

void sha_decrypt (char *input_filename, char *output_filename) {

}
