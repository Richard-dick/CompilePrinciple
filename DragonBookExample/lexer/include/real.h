#ifndef __REAL_H
#define __REAL_H

#include "token.h"
#include "tag.h"

class Real:Token {
public:
	float value;
	Real(float v);
    ~Real();
	string toString();
};

#endif




