#include "main.h"
#include "des.h"

void pbin(uint64_t input) {
    for (int i = 0; i < 64; i++) {
        if ((input >> i) & 1) 
            printf("1");
        else
            printf("0");
    }
}

uint64_t initial_permutation(uint64_t input) {
    uint64_t output = 0;
    for (int i = 0; i < 64; i++) {
        output |= ((input >> (64 - IP_ARR[i])) & 1) << (63 - i);
    }
    return output;
}

uint64_t key_schedule(uint64_t key){

}

uint64_t f(uint32_t chunk, uint64_t key){

}

uint64_t e(uint32_t chunk){

}

uint32_t p(uint32_t chunk){

}

void des_encrypt(char *input_filename, char *key, char *output_filename) {

}

void des_decrypt(char *input_filename, char *key_filename, char *output_filename) {

}
