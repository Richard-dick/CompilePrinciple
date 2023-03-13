#include<cstdio>





int main(int argc , char *argv[])
{
    Lexer *lex = new Lexer();        // ! 创建一个词法分析器
    Parser *parse = new Parser(lex); // ! 创建一个语法分析器
    parse->program();
    printf("\n");
}