#include "lexer.h"


Lexer::Lexer()
{
   // ! 需要将保留字初始化入hash表中
   reserve( new Word("if",    IF)    );
   reserve( new Word("else",  ELSE)  );
   reserve( new Word("while", WHILE) );
   reserve( new Word("do",    DO)    );
   reserve( new Word("break", BREAK) );

   reserve( _True );  
   reserve( _False );

   // reserve( Type.Int  );  reserve( Type.Char  );
   // reserve( Type.Bool );  reserve( Type.Float );
}

Lexer::~Lexer() {}

void Lexer::readch()
{
   peek = getchar();
}

bool Lexer::readch(char c)
{
   readch();
   if( peek != c ) return false;
   peek = ' ';
   return true;
}

Token* Lexer::scan()
{
   for( ; ; readch() ) {
      if( peek == ' ' || peek == '\t' ) continue;
      else if( peek == '\n' ) line = line + 1;
      else break;
   }
   switch( peek ) {
   case '&':
      if( readch('&') ) return _and;  else return new Token('&');
   case '|':
      if( readch('|') ) return _or;   else return new Token('|');
   case '=':
      if( readch('=') ) return _eq;   else return new Token('=');
   case '!':
      if( readch('=') ) return _ne;   else return new Token('!');
   case '<':
      if( readch('=') ) return _le;   else return new Token('<');
   case '>':
      if( readch('=') ) return _ge;   else return new Token('>');
   }
   if( isdigit(peek) ) {
      int v = 0;
      do {
         v = 10*v + Character.digit(peek, 10); readch();
      } while( isdigit(peek) );
      if( peek != '.' ) return new Num(v);
      float x = v; float d = 10;
      for(;;) {
         readch();
         if( ! Character.isDigit(peek) ) break;
         x = x + Character.digit(peek, 10) / d; d = d*10;
      }
      return new Real(x);
   }
   if( Character.isLetter(peek) ) {
      StringBuffer b = new StringBuffer();
      do {
         b.append(peek); readch();
      } while( Character.isLetterOrDigit(peek) );
      String s = b.toString();
      Word w = (Word)words.get(s);
      if( w != null ) return w;
      w = new Word(s, ID);
      words.put(s, w);
      return w;
   } 
   Token tok = new Token(peek); peek = ' ';
   return tok;
}