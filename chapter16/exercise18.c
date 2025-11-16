#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;

typedef enum color { BLACK, WHITE } Color;

typedef struct square {
	Piece p;
	Color c;
} Square;

char square_piece_char(Square s);

Square board[8][8] = {
	{{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK},
	 {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}},
	{{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK},
	 {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}},
	{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
	 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
	{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
	 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
	{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
	 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
	{{EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
	 {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}},
	{{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
	 {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}},
	{{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},
	 {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}},
};

int main(void)
{
	char ch[8][8];

	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			ch[rank][file] = square_piece_char(board[rank][file]);

			if (board[rank][file].p == EMPTY &&
			    (rank + file) % 2 == 1)
				ch[rank][file] = '.';

			printf("%c", ch[rank][file]);

			if (file % 8 == 7)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	return 0;
}

char square_piece_char(Square s)
{
	char ch;

	switch (s.p) {
	case EMPTY:
		ch = ' ';
		break;
	case PAWN:
		ch = 'p';
		break;
	case KNIGHT:
		ch = 'n';
		break;
	case BISHOP:
		ch = 'b';
		break;
	case ROOK:
		ch = 'r';
		break;
	case QUEEN:
		ch = 'q';
		break;
	case KING:
		ch = 'k';
		break;
	default:
		printf("Error: invalid piece\n");
		exit(EXIT_FAILURE);
	}

	if (s.c == WHITE)
		ch = toupper(ch);

	return ch;
}
