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


uint32_t *pad(char *input, int chunkNum) {
    uint32_t output[16] = {0};
    int blockNum = 0;
    for (int i = 0; i < sizeof(input) - 1; i++) { // plaintext in binary
        if (i/4 > blockNum) {
            blockNum++;
        }
        pbin(output[blockNum], 32);
        output[blockNum] = output[blockNum] << 8;
        pbin(output[blockNum], 32);
        output[blockNum] |= input[i];
        pbin(output[blockNum], 32);
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
    uint32_t initialArray[64];
    int f = open(input_filename, O_RDONLY);
    FILE * fil = fopen(input_filename, O_RDONLY);
    fseek(fil, 0, SEEK_END);
    unsigned long fileLength = ftell(fil);
    double chunks = trunc(fileLength / 512)+1;
}

void sha_decrypt (char *input_filename, char *output_filename) {

}
