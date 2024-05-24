#include "main.h"
#include "sha.h"

uint64_t pad(uint64_t input, uint64_t bit_num, uint64_t plaintext_length) {
    int first_pad = 0b1;
    int zero_pad = 0b0;
    uint64_t output = (input << 1) | first_pad;
    for (int i = 0; i < (448%512 - 1 - bit_num); i++) {
        output = (output << 1) | zero_pad;
    }
    // return 0ULL;
    return output;
}

void sha_encrypt (char *input_filename, char *output_filename) {

}

void sha_decrypt (char *input_filename, char *output_filename) {

}
