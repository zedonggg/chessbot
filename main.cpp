#include <iostream>
#include "defs.h"

int main() {
    // char BISHOP_B = 'b';
    // char KNIGHT_B = 'k';
    // char PAWN_B = 'p';
    // char QUEEN_B = 'q';
    // char KING_B = 'k';
    // char ROOK_B = 'r';

    // char BISHOP_W = 'B';
    // char KNIGHT_W = 'K';
    // char PAWN_W = 'P';
    // char QUEEN_W = 'Q';
    // char KING_W = 'K';
    // char ROOK_W = 'R';

    // char chessBoard[8][8] = {
    //     {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    //     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    //     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    //     {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    // };

    // for (int i = 0; i < 8; i++) {
    //     std::cout << "+---+---+---+---+---+---+---+---+\n";
    //     for (int j = 0; j < 8; j++) {
    //         std::cout << "| " << chessBoard[i][j] << " ";
    //     }
    //     std::cout << "|\n";
    // }
    // std::cout << "+---+---+---+---+---+---+---+---+\n";

    init_all();

    U64 test_board = 0ULL;
    test_board |= (1ULL << big_to_small[D2]);
    test_board |= (1ULL << big_to_small[D3]);
    test_board |= (1ULL << big_to_small[D4]);

    print_bb(test_board);
    std::cout << '\n';
    std::cout << bb_count(test_board);
    std::cout << pop_bit(&test_board);
    print_bb(test_board);

    return 0;
}
