#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <assert.h>

// #define DEBUG

// #ifndef DEBUG
// #define ASSERT(x)
// #else
// #define ASSERT(x) \
// if (! (x)) { \ 
//     printf("%s Failed", #x); \
//     exit(1);}
// #endif

typedef unsigned long long U64;

#define TOTAL_SQ 120
#define MAX_GAME_MOVES 2048

enum { EMPTY, WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ , BK};
enum { A, B, C, D, E, F, G, H, F_NONE };
enum { R1, R2, R3, R4, R5, R6, R7, R8, R_NONE };
enum { WHITE, BLACK, BOTH };
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

enum { wk_cast = 1, wq_cast, bk_cast = 4, bq_cast = 8 };

class UNDO {

    int move;
    int castle_perm;
    int enpass;
    int fifty_move;
    U64 posKey;

};

class chessboard {

    int board[TOTAL_SQ];
    U64 pawns[3];

    int king_square[2]; 

    int side;
    int enpass;
    int fifty_move;

    int ply;
    int hist_ply;

    int castle_perm;

    U64 posKey;

    int piece_count[13];
    int big_pieces[3];
    int maj_pieces[3];
    int min_pieces[3];

    int piece_list[13][10];

    UNDO history[MAX_GAME_MOVES];
};

#define rank_to_file(r, f) ((f + 21) + (r * 10))

extern int big_to_small[TOTAL_SQ];
extern int small_to_big[64];

extern void init_all();
extern void print_bb(U64 board);
extern int pop_bit(U64 *x);
extern int bb_count(U64 board);

#endif