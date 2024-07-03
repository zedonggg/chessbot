#include "defs.h"

int big_to_small[TOTAL_SQ];
int small_to_big[64];

void init_squares() {

    for (int i = 0; i < TOTAL_SQ; i++) {
        big_to_small[i] = 65;
    }

    int counter { 0 };

    for (int r = R1; r <= R8; r++) {
        for (int f = A; f < F_NONE; f++) {
            int sq { rank_to_file(r, f) };
            big_to_small[sq] = counter;
            small_to_big[counter] = sq;
            counter++;
        }
    }

}

void init_all() {

    init_squares();
    
}