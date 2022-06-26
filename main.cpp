#include <iostream>
#include "BET.h"

int main() {
    BET t1;
    cout << t1.empty() << endl;
    BET a1("4 50 6 + + 2 *");

    a1.PrintInfixExpression();
    a1.PrintPostfixExpression();
    cout << a1.empty() << endl;


    return 0;
}
