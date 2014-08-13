#include <iostream>
#include <fstream>
#include "lexer.h"

using namespace std;

int main(void) {
    ifstream f("test.obr", ifstream::in);
    if (f.is_open()) {
        Lexer l(&f);

        Token t;
        while ((t = l.nextToken()).getKind() != Token::END_OF_FILE) {
            switch(t.getKind()) {
            case Token::STRLITERAL:
                cout << "STR: " << t.getText() << endl;
                break;
            case Token::INTLITERAL:
                cout << "INT: " << t.getIntVal() << endl;
                break;
            case Token::FLOATLITERAL:
                cout << "FLOAT: " << t.getFloatVal() << endl;
                break;
            case Token::IDENTIFIER:
                cout << "IDENTIFIER: " << t.getText() << endl;
                break;
            case Token::OPERATOR:
                cout << "OPERATOR: " << t.getText() << endl;
                break;
            case Token::SEMICOLON:
                cout << "SEMICOLON" << endl;
                break;
            case Token::ASSIGNMENT:
                cout << "ASSIGNMENT" << endl;
                break;
            case Token::COLON:
                cout << "COLON" << endl;
                break;
            case Token::DOT:
                cout << "DOT" << endl;
                break;
            case Token::RANGE:
                cout << "RANGE" << endl;
                break;
            case Token::LPAREN:
                cout << "LPAREN" << endl;
                break;
            case Token::RPAREN:
                cout << "RPAREN" << endl;
                break;
            case Token::LCURLY:
                cout << "LCURLY" << endl;
                break;
            case Token::RCURLY:
                cout << "RCURLY" << endl;
                break;
            case Token::MODULE:
            case Token::BEGIN:
            case Token::END:
            case Token::PROCEDURE:
            case Token::RETURN:
            case Token::VAR:
            case Token::CONST:
            case Token::TYPE:
            case Token::IF:
            case Token::THEN:
            case Token::ELSIF:
            case Token::ELSE:
            case Token::REPEAT:
            case Token::UNTIL:
            case Token::WHILE:
            case Token::DO:
                cout << t.getText() << endl;
                break;
            default:
                cout << "OTHER: " << t.getText() << endl;
            }
        }

        f.close();
    }
    return 0;
}
