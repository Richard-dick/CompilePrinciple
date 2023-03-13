// file : num.cpp
// 解决数字问题

#include "num.h"

Num::Num(int v)
{
	tag = NUM;
	value = v;
}

Num::~Num(){}

string Num::toString()
{
	return std::to_string(value);
}