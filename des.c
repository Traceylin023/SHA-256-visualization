#include "main.h"
#include "des.h"

void pbin(uint64_t input, int size) {
    char count = 0;
    for (int i = size - 1; i >= 0; i--) {
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

uint64_t * split_l_r(uint64_t input) {
    uint64_t *output = malloc(2 * sizeof(uint64_t));
    output[0] = input >> 32;
    output[1] = input & 0xFFFFFFFF;
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

uint64_t key_schedule(uint64_t key, int round) {
    uint64_t key_c = key_shift(pc_1_c(key), round);
    uint64_t key_d = key_shift(pc_1_d(key), round);

    key_c = key_shift(pc_1_c(key), round);
    key_d = key_shift(pc_1_d(key), round);

    return pc_2(key_c, key_d);
}

uint64_t key_shift(uint64_t key, int round) {
    key = key << SHIFTS[round] | key >> (28 - SHIFTS[round]);
    return key;
}

uint64_t pc_2(uint64_t c, uint64_t d) {
    uint64_t combined = c << 28 | d;
    uint64_t key = 0;

    for (int i = 0; i < 48; i++) {
        key |= ((combined >> (56 - PC_2_ARR[i])) & 1) << (47 - i);
    }

    return key;
}

uint64_t e(uint64_t chunk){
    uint64_t output = 0;
    for (int i = 0; i < 48; i++) {
        output |= ((chunk >> (32 - E_ARR[i])) & 1) << (47 - i);
    }
    return output;
}

uint64_t in_key_xor(uint64_t input, uint64_t key) {
    uint64_t output = 0;
    for (int i = 0; i < 48; i++) {
        output |= (((input >> (47 - i)) & 1) ^ ((key >> (47 - i)) & 1)) << (47 - i);
    }
    return output;
}

uint64_t s_boxes(uint64_t xored_chunk) {

    uint8_t small_chunks[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    uint64_t output = 0;

    for (int i = 0; i < 8; i++) {
        small_chunks[i] = xored_chunk >> (48 - 6 * (i + 1)) & 63;
    }

    for (int i = 0; i < 8; i++) {
        int row = (small_chunks[i] >> 5 << 1) | (small_chunks[i] & 1);
        int col = (small_chunks[i] & ~(1 << 5) & ~1) >> 1;
        output = output << 4;
        output |= S_PRIM_ARR[i][row * 16 + col];
    }

    return output;
}

uint64_t f(uint64_t chunk, uint64_t key) {
    return 0ULL;
}

uint64_t p(uint64_t chunk) {
    uint64_t output = 0;
    for (int i = 0; i < 32; i++) {
        output |= ((chunk >> (32 - P_ARR[i])) & 1) << (31 - i);
    }
    return output;
}

void des_encrypt(char *input_filename, char *key, char *output_filename) {

}

void des_decrypt(char *input_filename, char *key_filename, char *output_filename) {

}
