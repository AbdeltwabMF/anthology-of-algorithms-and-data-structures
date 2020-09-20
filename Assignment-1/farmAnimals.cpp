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
    }

    animal(string _name, int r, int c) {
        rowPosition = r;
        columnPosition = c;
        name = _name;
    }

    bool move(char c) {
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

};

bool isEaten(int r, int c)
{
    return (Board.getBoardCell(r, c) == 'C');
}

bool isEscaped(int r, int c)
{
    return (Board.getBoardCell(r, c) == 'B');
}

bool isDrowned(bool ok)
{
    return !ok;
}

int main() {

    int boardSize;
    cin >> boardSize;

    int c1r, c1c, c2r, c2c;
    cin >> c1r >> c1c >> c2r >> c2c;

    Board = board(c1r, c1c, c2r, c2c, boardSize);

    int numOfFarmAnimals;
    cin >> numOfFarmAnimals;


    animal animals[numOfFarmAnimals];

    for(int i = 0; i < numOfFarmAnimals; ++i) {

        int r, c;
        string name;
        cin >> name >> r >> c;

        animals[i] = animal(name, r, c);
    }

    for(int i = 0; i < numOfFarmAnimals; ++i) {

        string movement;
        cin >> movement;

        bool ok = false;
        string name = animals[i].getName();

        for(int j = 0; j < movement.size(); ++j)
        {
            bool status = animals[i].move(movement[j]);
            int r = animals[i].getRow();
            int c = animals[i].getColumn();

            if(isDrowned(status))
            {
                cout << name << ": Drowned outside the island." << endl;
                ok = true;
                break;
            }
            else if(isEaten(r, c))
            {
                cout << name << ": Eaten by the cat." << endl;
                ok = true;
                break;
            }
            else if(isEscaped(r, c))
            {
                cout << name << ": Escaped through the bridge." << endl;
                ok = true;
                break;
            }
        }

        if(!ok)
            cout << name << ": Starved… Stuck inside the board." << endl;
    }
}
