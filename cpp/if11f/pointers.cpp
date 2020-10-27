#include <iostream>

using namespace std;

int main()
{
    int i = 5;
    int *pi, pj;
    char *pc, pd;
    int a = 0;
    pi = &a;
    pj = 0;
    pd = '0';

    // pi = i;
    // i is int and pi pointer int, no direct assignment allowed

    // pi = *i;
    // should be pi = &i, * is the wrong operand

    *pi = i;
    // the adress pi points to gets set to the value of i (5)

    // *pi = &i;
    // *pi points to the value and &i to an adress

    // pi = pj;
    // pj is an int, to define multiple pointers it should be: int *pi, *pj;

    pc = &pd;
    // pc now points to the adress of pd

    // pi = pc;
    // different pointer types, pi is a int pointer and pc a char pointer

    pd = *pi;
    // pd which is a char gets assigned the value pi is pointing to which is a int so the value gets casted to char

    *pi = i**pc;
    // adress of pi gets assigned i * value of pc

    pi = 0;

    cout << "i: " << i << "  " << &i << endl;
    cout << "pi: " << pi << "  " << &pi << endl;
    cout << "pj: " << pj << "  " << &pj << endl;
    cout << "pc: " << pc << "  " << &pc << endl;
    cout << "pd: " << pd << "  " << &pd << endl;
    cout << "a: " << a << "  " << &a << endl;
}
