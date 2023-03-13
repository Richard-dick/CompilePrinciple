#ifndef __WORD_H
#define __WORD_H

#include "token.h"
#include "tag.h"

class Word: public Token {
public:
   string lexeme = "";
   Word(string s, int tag);
   ~Word();
   string toString();

   
};

Word* _and = new Word( "&&", AND);
Word* _or = new Word( "||", OR);
Word* _eq  = new Word( "==", EQ  );
Word* _ne = new Word( "!=", NE );
Word* _le  = new Word( "<=", LE  );
Word* _ge = new Word( ">=", GE );
Word* _minus  = new Word( "minus", MINUS );
Word* _True   = new Word( "true",  TRUE  );
Word* _False  = new Word( "false", FALSE );
Word* _temp   = new Word( "t",     TEMP  );

#endif