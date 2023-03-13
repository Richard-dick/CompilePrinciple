#include "word.h"

Word::Word(string s, int tag) 
{ 
    this->tag = tag;
    lexeme = s; 
}


Word::~Word() {}


string Word::toString() { return lexeme; }


