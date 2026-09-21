#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int Max = arr[0];
    int Min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }

    cout << Min << " " << Max << endl;

    return 0;
}