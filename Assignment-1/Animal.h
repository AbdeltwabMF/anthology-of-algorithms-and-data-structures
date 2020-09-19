#ifndef ANIMAL_H
#define ANIMAL_H
#include "board.h"

using namespace std;

class Animal {
  public:
    Animal() {
        rowPosition = 0;
        columnPosition = 0;
        name = "";
    }

    Animal(int r, int c, string _name) {
        rowPosition = r;
        columnPosition = c;
        name = _name;
    }

    bool move(char c) {
        if(c == 'U') {
            if(--rowPosition < 0) return false;
        } else if(c == 'D') {
            if(++rowPosition >= board().getBoardSize()) return false;
        } else if(c == 'R') {
            if(++columnPosition >= board().getBoardSize()) return false;
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

#endif // ANIMAL_H
