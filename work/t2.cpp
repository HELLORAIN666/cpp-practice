#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum << endl;

    return 0;
}