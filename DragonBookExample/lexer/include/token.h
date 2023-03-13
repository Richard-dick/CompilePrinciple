#ifndef __TOKEN_H
#define __TOKEN_H

#include <iostream>
using std::string;

class Token{
public:
    int tag;
    Token() = default;
    Token(int t);
    ~Token();
    string toString();
};

#endif