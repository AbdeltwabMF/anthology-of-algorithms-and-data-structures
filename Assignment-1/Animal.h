#ifndef ANIMAL_H
#define ANIMAL_H

#include "board.h"

using namespace std;

class Animal {
  public:
    Animal() {
    	name = "";
        rowPosition = 0;
        columnPosition = 0;
    }

    Animal(string _name, int r, int c) {
        name = _name;
        rowPosition = r;
        columnPosition = c;
    }

    bool move(char c) {
        if(c == 'U') {
            if(--rowPosition < 0) return false;
        } else if(c == 'D') {
            if(++rowPosition >= board().getBoardSize()) return false;
        } else if(c == 'R') {
            if(++columnPosition >= board().getBoardSize()) return false;
        } else if(c == 'L') {
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

#endif
