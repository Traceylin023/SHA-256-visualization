#include "main.h"
#include "sha.h"

void pbin(uint64_t input, int size) {
    char count = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (count++ % 8 == 0) printf(" ");
        if ((input >> i) & 1) printf("1");
        else                  printf("0");
    }
    printf("\n");
}

char* rbin(uint64_t input, int size) {
    return 0ULL;
}

uint64_t pad(uint64_t input) {
    uint64_t output = 0;
    return 0ULL;
}
void sha_encrypt (char *input_filename, char *output_filename) {

}

void sha_decrypt (char *input_filename, char *output_filename) {

}
