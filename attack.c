BOOL attack(int sq, int s)
{
	int i, j, n;
	int index_piece;

	for (index_piece = 1; index_piece < 17; ++index_piece) {
		if (s == LIGHT)
			i = pospiece[index_piece];
		else
			i = pospiece[index_piece + 16];

		if (i == PIECE_DEAD)
			continue;
		if (color[i] == s) {
			if (piece[i] == PAWN) {
				if (s == LIGHT) {
					if (COL(i) != 0 && i - 9 == sq)
						return TRUE;
					if (COL(i) != 7 && i - 7 == sq)
						return TRUE;
				}
				else {
					if (COL(i) != 0 && i + 7 == sq)
						return TRUE;
					if (COL(i) != 7 && i + 9 == sq)
						return TRUE;
				}
			}
			else
				for (j = 0; j < offsets[piece[i]]; ++j)
					for (n = i;;) {
						n = mailbox[mailbox64[n] + offset[piece[i]][j]];
						if (n == -1)
							break;
						if (n == sq)
							return TRUE;
						if (color[n] != EMPTY)
							break;
						if (!slide[piece[i]])
							break;
					}
		}
	}
	return FALSE;
}