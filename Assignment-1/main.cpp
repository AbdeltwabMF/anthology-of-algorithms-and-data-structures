#include <bits/stdc++.h>

#include "Animal.h"
#include "board.h"

using namespace std;

bool isEaten(int r, int c)
{
    if(board().getBoardCell(r, c) == 'C')
    	return true;
    else
        return false;
}

bool isEscaped(int r, int c)
{
    if(board().getBoardCell(r, c) == 'B')
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
        cin >> name >> r >> c;

        animals[i] = Animal(name, r, c);
    }

    string movement;
    for(int i = 0; i < numOfFarmAnimal; ++i) {
        cin >> movement;

        bool ok = false;
        for(int j = 0; j < movement.size(); ++j)
        {
            if(!animals[i].move(movement[j]))
            {
                cout << animals[i].getName() << ": Drowned outside the island." << endl;
                ok = true;
                break;
            }
            else if(isEaten(animals[i].getRow(), animals[i].getColumn()))
            {
                cout << animals[i].getName() << ": Eaten by the cat." << endl;
                ok = true;
                break;
            }
            else if(isEscaped(animals[i].getRow(), animals[i].getColumn()))
            {
                cout << animals[i].getName() << ": Escaped through the bridge." << endl;
                ok = true;
                break;
            }
        }
        
        if(!ok) 
            cout << animals[i].getName() << ": Starved… Stuck inside the board." << endl;
    }
}
