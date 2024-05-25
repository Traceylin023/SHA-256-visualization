#include <stdio.h>
#include "main.h"
#include "des.h"
#include "sha.h"

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

}

void sha_decrypt (char *input_filename, char *output_filename) {

}
