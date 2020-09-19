#ifndef BOARD_H
#define BOARD_H


class board {
  public:
    board() {};

    board(int c1r, int c1c, int c2r, int c2c, int sz) {
        boardSize = sz;

        for(int i = 0; i < boardSize; ++i)
            for(int j = 0; j < boardSize; ++j)
                Board[i][j] = '-';

        Board[c1r][c1c] = 'C';
        Board[c2r][c2c] = 'C';
        Board[boardSize / 2][boardSize - 1] = 'B';
    }

    int getBoardSize() {
        return boardSize;
    }

    char getBoardCell(int r, int c) {
        return Board[r][c];
    }

  private:
    int boardSize;
    char Board[12][12];
};

#endif // BOARD_H
