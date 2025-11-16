#include <stdio.h>

enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

const int piece_value[] = {
	[KING] = 200,
	[QUEEN] = 9,
	[ROOK] = 5,
	[BISHOP] = 3,
	[KNIGHT] = 3,
	[PAWN] = 1,
};

int main(void)
{
	printf("Piece  Value\n");
	printf("KING   %-5d\n", piece_value[KING]);
	printf("QUEEN  %-5d\n", piece_value[QUEEN]);
	printf("ROOK   %-5d\n", piece_value[ROOK]);
	printf("BISHOP %-5d\n", piece_value[BISHOP]);
	printf("KNIGHT %-5d\n", piece_value[KNIGHT]);
	printf("PAWN   %-5d\n", piece_value[PAWN]);

	return 0;
}
