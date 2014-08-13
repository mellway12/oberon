#pragma once

#include <iostream>
#include <string>

struct Location {
    unsigned int line, column;
};

class Token {
public:
    enum Kind {
        INTLITERAL, FLOATLITERAL, STRLITERAL, CHARLITERAL, IDENTIFIER, OPERATOR,
        MODULE, BEGIN, END, PROCEDURE, RETURN, VAR, CONST, TYPE,
        IF, THEN, ELSIF, ELSE,
        REPEAT, UNTIL, WHILE, DO,
        DOT, RANGE, COMMA, COLON, SEMICOLON, ASSIGNMENT, LPAREN, RPAREN, LCURLY, RCURLY,
        END_OF_FILE, OTHER
    };

    Token() : kind(END_OF_FILE), loc{0, 0}, text("") {}
    Token(Kind kind, Location loc) : kind(kind), loc(loc), text("") {}
    Token(Kind kind, Location loc, int intval) : kind(kind), loc(loc), text(""), intval(intval) {}
    Token(Kind kind, Location loc, double floatval) : kind(kind), loc(loc), text(""), floatval(floatval) {}
    Token(Kind kind, Location loc, std::string text);

    Kind getKind() const         { return kind; }
    Location getLocation() const { return loc; }
    std::string getText() const  { return text; }
    int getIntVal() const        { return intval; }
    double getFloatVal() const   { return floatval; }
private:
    Kind kind;
    Location loc;
    std::string text;
    int intval;
    double floatval;
};

class Lexer {
public:
    Lexer(std::istream *in)
        : in(in), loc{0, 0} {}
    Token nextToken(void);
private:
    void take(void);

    std::istream *in;
    Location loc;
    char lastChar;
};

