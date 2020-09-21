#include <bits/stdc++.h>

using namespace std;

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

} Board;

class animal {

  public:
    animal() {
        rowPosition = 0;
        columnPosition = 0;
        name = "";
        instructions = 0;
    }

    animal(string _name, int r, int c) {
        rowPosition = r;
        columnPosition = c;
        name = _name;
        instructions = 4;
    }

    bool move(char c) {
        --instructions;
        
        if(c == 'U') {
            if(--rowPosition < 0) return false;
        } else if(c == 'D') {
            if(++rowPosition >= Board.getBoardSize()) return false;
        } else if(c == 'R') {
            if(++columnPosition >= Board.getBoardSize()) return false;
        } else {
            if(--columnPosition < 0) return false;
        }

        return true;
    }
	
	bool isEaten() {
		return Board.getBoardCell(rowPosition, columnPosition) == 'C';
	}

	bool isEscaped() {
		return Board.getBoardCell(rowPosition, columnPosition) == 'B';
	}

	bool isDrowned(bool status) {
		return !status;
	}

	bool isStuck() {
		return instructions == 0;
	}
	
    int getRow() {
        return rowPosition;
    }

    int getColumn() {
        return columnPosition;
    }

    string getName() {
        return name;
    }

  private:
    string name;
    int rowPosition;
    int columnPosition;
	int instructions;
	
};


int main() {

    int boardSize;
    cin >> boardSize;

    int c1r, c1c, c2r, c2c;
    cin >> c1r >> c1c >> c2r >> c2c;

    Board = board(c1r, c1c, c2r, c2c, boardSize);

    int nAnimals;
    cin >> nAnimals;


    animal animals[nAnimals];

    for(int i = 0; i < nAnimals; ++i) {

        int r, c;
        string name;
        cin >> name >> r >> c;

        animals[i] = animal(name, r, c);
    }

    for(int i = 0; i < nAnimals; ++i) {

        string movement;
        cin >> movement;

        string name = animals[i].getName();

        for(int j = 0; j < (int)movement.size(); ++j) {
            
            bool status = animals[i].move(movement[j]);
        
            if(animals[i].isDrowned(status)) {
                cout << name << ": Drowned outside the island." << endl;
                break;
            }
            else if(animals[i].isEaten()) {
                cout << name << ": Eaten by the cat." << endl;
                break;
            }
            else if(animals[i].isEscaped()) {
                cout << name << ": Escaped through the bridge." << endl;
                break;
            }
            else if(animals[i].isStuck()) {
				cout << name << ": Starved… Stuck inside the board." << endl;
			}
        }
    }
}

