#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;
    cin >> a >> op >> b;

    switch (op)
    {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if (b == 0)
            {
                cout << "Error!" << endl;
            }
            else
            {
                cout << a / b << endl;
            }
            break;
        default:
            break;
    }

    return 0;
}