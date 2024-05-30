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
// #include "message.txt"


int err(int line){
    printf("line: %d\n",line);
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

uint32_t rotate(uint32_t input, int shift){
    return input >> shift | input << (32-shift);
}   

uint32_t funct0(uint32_t n0){
    uint32_t a = rotate(n0, 7);
    uint32_t b = rotate(n0, 18);
    uint32_t c = n0 >> 3;
    return ((a ^ b) ^ c);
}

uint32_t funct1(uint32_t n0){
    uint32_t a = rotate(n0, 17);
    uint32_t b = rotate(n0, 9);
    uint32_t c = n0 >> 10;
    return ((a ^ b) ^ c);
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

void sha_encrypt(char *input_filename, char *output_filename) {

    /* READ FILE INTO ARRAY */

    // Get num_chunks = (length of the file / 512) + 1
    // Create an array of num_chunks long
    // Read file char by char into buffer
    // For each char, write to the count / 4th index of the array
    // Shift the array[count/4] by 8, then OR the buffer into the array[count/4]

    FILE * file = fopen(input_filename, "r");

    fseek(file, 0, SEEK_END);
    uint64_t fileLength = ftell(file);
    int num_chunks = (int) (trunc(fileLength / 64) + 1);
    fseek(file, 0, SEEK_SET);

    printf("size: %ld\n", fileLength);
    printf("num_chunks: %d\n", num_chunks);

    char *array = malloc(fileLength * sizeof(char));
    char buffer = 0;
    int counter = 0;

    while (fread(&buffer, sizeof(char), 1, file) == 1) {
        array[counter++] = buffer;
    }

    /* PREPROCESSING */

    uint32_t H[8] = {0,0,0,0,0,0,0,0};
    for (int i = 0; i < 8; i++) H[i] = HASH_ARR[i];

    uint32_t a, b, c, d, e, f, g, h;

    uint32_t t1 = 0;
    uint32_t t2 = 0;

    // TODO: Pad the array
    uint32_t *paddedData;
    paddedData = pad(array,num_chunks);
    /* HASH COMPUTATION */

       for (int i = 0; i < 32; i++) {
            if (i == 16) {
                printf("\n");
                printf("\n");
            }
            pbin(*(paddedData+i), 32);
        }

    uint32_t chunk = malloc(256);
    for(int i = 0; i < chunks; i++) {
    //     fread(array, 256, 1, file);
    //     pbin(array, 256);
        for(int j = 0; j < 16 ;j++){ //pull 16 lines of 4 bytes 
            chunk[j] = *(paddedData+16*i + j]);
        }
        for(int k = 0; k < 47; k++){ // calculate the rest of the array
            arr[k+16] = (arr[k] + funct0(arr[k+1]) + arr[k+9] + funct1(arr[k+14]));
        }
    // }
    // for(int i = 0; i < 64; i++){
    //     printf("line [%d]: ",i);
    //     pbin(arr[i], 32);
    }


    //funny testing :D
    // uint32_t var = 1;
    // pbin(var,32);
    // uint32_t v = rotate(var, 1);
    // pbin(v, 32);
    // fread(arr,4,64,file); //err(__LINE__);
    // fgets(arr,256,file); err(__LINE__);
    // printf("-----------------------------------------------------\n");
    // uint32_t a0 = arr[10];   
    // uint32_t r0  = rotate(a0, 7);
    // uint32_t r1  = rotate(a0, 18);
    // uint32_t r2  = a0 >> 3;
    // // printf("original:  ");
    // pbin(arr[10],32);
    // // pbin(arr[1],32);
    // printf("rotate 7:  ");
    // pbin(r0,32);
    // printf("rotate 18: ");
    // pbin(r1,32);
    // printf("shift 3:   ");
    // pbin(r2,32);
    // uint32_t z = ((r0 ^ r1 )^ r2);
    // printf("sigma:     ");
    // pbin(z,32);
    int output_file = open(output_filename, O_CREAT | O_WRONLY, 0644);
    int er = write(output_file, array, 64);// err(__LINE__);
}

void sha_decrypt (char *input_filename, char *output_filename) {

}
