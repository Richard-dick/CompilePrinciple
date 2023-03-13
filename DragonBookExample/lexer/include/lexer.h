#ifndef __LEXER_H
#define __LEXER_H

#include<iostream>
#include<unordered_map>
#include "word.h"
#include "tag.h"
#include "token.h"

using std::unordered_map;

class Lexer {
public:
   static int line;
   char peek = ' ';
   // Hashtable words = new Hashtable();
   // 创建一个空的hash表
   unordered_map<std::string, Word*> words;
   void reserve(Word* w) { words.insert({w->lexeme, w}); }

   Lexer();
   ~Lexer();
   void readch();
   bool readch(char c);
   Token* scan();
};



#endif