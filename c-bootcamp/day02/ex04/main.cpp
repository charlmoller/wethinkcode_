
#include <iostream>
#include <cstdlib>
#include "Fixed.class.hpp"

const int SIZE = 200;

template <class StackType> class Stack {
  StackType v[SIZE];
  int t;

public:
    Stack() { t = -1; }
    void push(StackType va) { v[++t] = va; }
    int empty() { return t < 0; }
    StackType pop() { return v[t--]; }
    StackType peek() { return v[t]; }
};

float readFloatAtString(std::string s, int& i) {
    std::string buff = "";
    if (s[i] == '-') {
        buff += '-';
        i++;
    }
    while( (s[i] >= '0' && s[i] <= '9') || s[i] == '.' ) {
        buff += s[i++];
    }
    i--;
	float f = (float) atof( buff.c_str() );
    return f;
}

void popExpression(char op, Stack<Fixed>& vals) {
    Fixed v2 = vals.pop();
    Fixed v1 = vals.pop();
    if      (op == '+') vals.push( v1 + v2 );
    else if (op == '-') vals.push( v1 - v2 );
    else if (op == '*') vals.push( v1 * v2 );
    else if (op == '/') vals.push( v1 / v2 );
}

int main( int argc, char *argv[] ) {


	if (argc == 2) {

        Stack<char> ops;
        Stack<Fixed> vals;

        std::string s = argv[1];
        for (int i = 0; s[i]; ++i) {

            if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && (s[i+1] >= '0' && s[i+1] <= '9')) ) {

                vals.push( Fixed( readFloatAtString(s, i) ) );

            } else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='(') {

                ops.push( s[i] );

            } else if (s[i]==')') {

				for (char op; ((op = ops.pop()) != '('); popExpression(op, vals));

            }
        }

        for(; !ops.empty(); popExpression(ops.pop(), vals));
        std::cout << vals.pop() << "\n";

	} else std::cout << "Please provide one expression: ./eval_expr \"(1 + 2)\"\n";
	return 0;
}
