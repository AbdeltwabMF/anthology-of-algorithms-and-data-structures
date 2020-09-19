#include <bits/stdc++.h>
#include "Animal.h"
#include "board.h"

using namespace std;

bool isEaten(int c1r, int c1c, int c2r, int c2c, int r, int c)
{
    if((r == c1r && c == c1c) || (r == c2r && c == c2c))
        return true;
    else
        return false;
}

bool isEscaped(int r, int c, int boardSize)
{
    if(c == boardSize - 1 && r == (boardSize / 2))
        return true;
    else
        return false;
}

int main() {
    int boardSize;
    cin >> boardSize;

    int c1r, c1c, c2r, c2c;
    cin >> c1r >> c1c >> c2r >> c2c;

    board Board = board(c1r, c1c, c2r, c2c, boardSize);

    int numOfFarmAnimal;
    cin >> numOfFarmAnimal;

    int r, c;
    string name;
    Animal animals[numOfFarmAnimal];

    for(int i = 0; i < numOfFarmAnimal; ++i) {
        cin >> r >> c >> name;

        animals[i] = Animal(r, c, name);
    }

    string movement;
    for(int i = 0; i < numOfFarmAnimal; ++i) {
        cin >> movement;

        bool ok = false;
        for(int j = 0; j < movement.size(); ++j)
        {
            if(!animals[i].move(movement[j]))
            {
                cout << animals[i].getName() << " Drowned outside the island." << endl;
                ok = true;
                break;
            }
            else if(isEaten(c1r, c1c, c2r, c2c, animals[i].getRow(), animals[i].getColumn()))
            {
                cout << animals[i].getName() << " Eaten by the cat." << endl;
                ok = true;
                break;
            }
            else if(isEscaped(animals[i].getRow(), animals[i].getColumn(), boardSize))
            {
                cout << animals[i].getName() << " Escaped through the bridge." << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << animals[i].getName() << " Starved… Stuck inside the board." << endl;
    }
}
