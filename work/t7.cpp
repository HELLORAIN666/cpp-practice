#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int base = N / M;
    int rest = N % M;

    for (int i = 1; i <= M; i++)
    {
        int value = (i <= M - rest) ? base : base + 1;

        if (i > 1)
        {
            cout << " ";
        }
        cout << value;
    }
    cout << endl;

    return 0;
}
