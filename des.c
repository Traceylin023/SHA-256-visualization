#include "main.h"
#include "des.h"

void pbin(uint64_t input) {
    char count = 0;
    for (int i = 63; i >= 0; i--) {
        if (count++ % 8 == 0) printf(" ");
        if ((input >> i) & 1) printf("1");
        else                  printf("0");
    }
    printf("\n");
}

uint64_t initial_permutation(uint64_t input) {
    uint64_t output = 0;
    for (int i = 0; i < 64; i++) {
        output |= ((input >> (64 - IP_ARR[i])) & 1) << (63 - i);
    }
    return output;
}

uint64_t pc_1_c(uint64_t key) {
    uint64_t output = 0;
    for (int i = 0; i < 28; i++) {
        output |= ((key >> (64 - PC_1_ARR[i])) & 1) << (27 - i);
    }

    return output;
}

uint64_t pc_1_d(uint64_t key) {
    uint64_t output = 0;
    for (int i = 0; i < 28; i++) {
        output |= ((key >> (64 - PC_1_ARR[i + 28])) & 1) << (27 - i);
    }
    return output;
}

}

uint64_t e(uint32_t chunk){

}

uint32_t p(uint32_t chunk){

}

void des_encrypt(char *input_filename, char *key, char *output_filename) {

}

void des_decrypt(char *input_filename, char *key_filename, char *output_filename) {

}
