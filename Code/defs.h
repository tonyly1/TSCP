/*
 *	DEFS.H
 *	Tom Kerrigan's Simple Chess Program (TSCP)
 *
 *	Copyright 1997 Tom Kerrigan
 */


#define BOOL			int
#define TRUE			1
#define FALSE			0

#define GEN_STACK		1120
#define MAX_PLY			32
#define HIST_STACK		400

#define LIGHT			0
#define DARK			1

#define PAWN			0
#define KNIGHT			1
#define BISHOP			2
#define ROOK			3
#define QUEEN			4
#define KING			5

#define EMPTY			6

/* useful squares */
#define A1				56
#define B1				57
#define C1				58
#define D1				59
#define E1				60
#define F1				61
#define G1				62
#define H1				63
#define A8				0
#define B8				1
#define C8				2
#define D8				3
#define E8				4
#define F8				5
#define G8				6
#define H8				7

#define ROW(x)			(x >> 3)
#define COL(x)			(x & 7)

#define PIECE_DEAD (-1) //permet d'indiquer une pi�ce morte 
#define U64 unsigned long long //exercice bonus

#define MAX_TT (500000)
#define FLAG_L_BOUND	(1)
#define FLAG_U_BOUND	(2)
#define FLAG_VALID		(4)

/* This is the basic description of a move. promote is what
   piece to promote the pawn to, if the move is a pawn
   promotion. bits is a bitfield that describes the move,
   with the following bits:

   1	capture
   2	castle
   4	en passant capture
   8	pushing a pawn 2 squares
   16	pawn move
   32	promote

   It's union'ed with an integer so two moves can easily
   be compared with each other. */

typedef struct {
	char from;
	char to;
	char promote;
	char bits;
} move_bytes;

typedef union {
	move_bytes b;
	int u;
} move;

/* an element of the move stack. it's just a move with a
   score, so it can be sorted by the search functions. */
typedef struct {
	move m;
	int score;
} gen_t;

/* an element of the history stack, with the information
   necessary to take a move back. */
typedef struct {
	move m;
	int capture;
	int capturePiece;
	int castle;
	int ep;
	int fifty;
	unsigned int hash;
} hist_t;

typedef struct
{
	unsigned int hash;		// hash servant � v�rifier la validit�
							// de l�entr�e
	short score;
	unsigned char flag;		// indique si le score est FLAG_EXACT,
							// FLAG_LOW_BOUND ou FLAG_UPPER_BOUND
	unsigned char depth;	// Profondeur de reherche
} HtTyp;

#define SCALE_MATE_VALUE(value) \
{\
	if (value > 10000-MAX_PLY) \
		{value += (ply);};\
	if (value < -10000+MAX_PLY) \
		{value -= (ply);};\
}
#define UNSCALE_MATE_VALUE(value) \
{\
	if (value > 10000-MAX_PLY) \
		value -= (ply);\
	if (value < -10000+MAX_PLY) \
		value += (ply);\
}