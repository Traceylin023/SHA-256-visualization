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
    for (int i = 0; i < sizeof(input) - 1; i++) {
        output[i/4] << 8;
        output[i/4] |= input[i];
    }
    uint32_t one_pad = 0b1;
    uint32_t zero_pad = 0b0;
    uint32_t *ptr = output;
    // rrn 0ULL;
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
