/*
 * T4 最大值与最小值（数组与循环）
 * ------------------------------------------------------------
 * 思路：擂台赛（打擂台）
 *   先让第一个数站上"最大擂主"和"最小擂主"的位置，
 *   后面的数依次上来挑战：比我大就换人，比我小也换人。
 *
 * 关键陷阱：初始值不能随便设 0！
 *   如果所有数都是负数（比如 -5 -3 -1），你拿 0 当初始最大值，
 *   结果会输出 0 —— 但 0 根本不在数组里。
 *   正确做法：用数组的第一个元素当初始值（擂主必须是从参赛选手里选的）。
 *   或者把 maxVal 初始化为 INT_MIN，minVal 初始化为 INT_MAX（需要 <climits>）
 * ------------------------------------------------------------
 */
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

    // 擂主从数组中选，而不是凭空捏一个 0
    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++) // 从 1 开始，第 0 个已经是擂主了
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }

    cout << minVal << " " << maxVal << endl; // 注意题目要"先最小后最大"

    return 0;
}
