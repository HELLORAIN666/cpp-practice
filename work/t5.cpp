#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x; // 取出 x 指向的那个值
    *x = *y;       // 把 y 指向的值写进 x 指向的房间
    *y = temp;     // 再把原来的值写进 y 指向的房间
}

void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp; // 只换了副本，主函数的 a、b 不受影响
}

int main()
{
    int a, b;
    cin >> a >> b;

    swap(&a, &b); // & 是"取地址"：把 a 的门牌号交给函数

    cout << a << " " << b << endl;

    return 0;
}
