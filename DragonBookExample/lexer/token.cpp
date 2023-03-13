#include "token.h"

Token::Token(int t) {tag = t;};
Token::~Token() {};

string Token::toString()
{
    string tmp_string = "";
    return tmp_string.append(1, static_cast<char> (tag));
}