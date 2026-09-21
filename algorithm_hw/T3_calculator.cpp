/*
 * T3 简易计算器（switch 语句）
 * ------------------------------------------------------------
 * 思路：
 *   1. 输入格式是 "a op b"，例如 "10 + 3"，三个东西之间有空格
 *      → cin >> a >> op >> b; 就能自动按空格切开
 *   2. 根据 op 走不同的分支 → 这正是 switch 的用武之地
 *   3. 特判：除法时若 b == 0，输出 "Error!"
 *
 * switch 的本质：
 *   如果 if-else 是"一条一条问"，switch 就是"看号码直接跳到对应的房间"。
 *   它只能判断"整数/字符"这种能当号码的类型，不能直接判断字符串或范围。
 *
 * break 的血泪教训：
 *   switch 一旦跳进某个 case，会一路往下"滑"到后面的所有 case（穿透）。
 *   break 就是每个房间门口的"止步"牌子，忘了写就会执行别人的代码。
 * ------------------------------------------------------------
 */
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
                cout << a / b << endl; // int 相除自动向零取整
            }
            break;
        default:
            break;
    }

    return 0;
}
