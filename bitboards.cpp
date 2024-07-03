#include <iostream>
#include "defs.h"

const int bit_table[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};

int pop_bit(U64 *x) {
    U64 b = *x ^ (*x - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *x &= (*x - 1);
    return bit_table[(fold * 0x783a9b23) >> 26];
}

int bb_count(U64 x) {
    int count = 0;
    while (x) {
        count++;
        x &= x - 1;
    }
    return count;
}

void print_bb(U64 board) {
    
    U64 shifter = 1ULL;

    int cur{};
    int index_64{};

    std::cout << "\n";
    for (int i = R8; i >= R1; i--) {
        for (int f = A; f < F_NONE; f++) {
            cur = rank_to_file(i, f);
            index_64 = big_to_small[cur];

            if ((shifter << index_64) & board) {
                std::cout << "X";
            } else {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
}