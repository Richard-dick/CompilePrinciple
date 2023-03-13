#ifndef __NUM_H
#define __NUM_H

#include "token.h"
#include "tag.h"

using std::string;

class Num:Token {
public:
    int value;
	Num(int v);
    ~Num();
	string toString();
};

#endif