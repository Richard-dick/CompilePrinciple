#include "real.h"

Real::Real(float v)
{
	tag = REAL;
	value = v; 
}

Real::~Real()
{}

string Real::toString()  
{ 
	return std::to_string(value); 
}