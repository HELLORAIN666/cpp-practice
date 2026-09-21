/*
 * T9 最接近的三数之和（双指针）
 * ------------------------------------------------------------
 * 题目：从数组中选 3 个数，使它们的和最接近 target，返回这个和。
 *
 * 暴力法：三重循环 O(n^3)。n 一大就爆炸。
 *
 * 优化思路（本题灵魂）：
 *   先排序。然后固定第一个数 nums[i]，问题就变成了：
 *   "在 i 后面的区间里，找两个数，让它们的和最接近 target - nums[i]"
 *   —— 这就是经典的"两数之和最接近"，用双指针 O(n) 解决。
 *
 * 双指针为什么能工作？（一定要想明白，这是排序+双指针的核心套路）
 *   数组已升序，左指针 L 在头，右指针 R 在尾。
 *   看当前和 cur = nums[L] + nums[R]：
 *     - cur 太小 → 想变大，只能把 L 往右挪（换一个更大的数进来）
 *     - cur 太大 → 想变小，只能把 R 往左挪（换一个更小的数进来）
 *   因为数组有序，挪指针的效果是单调可预测的，所以不会漏掉最优解。
 *   指针总共只走 n 步，所以是 O(n)，套上外层 i 的循环 = O(n^2)。
 *
 *   比喻：你要在一排从矮到高排好队的人里找两个人身高之和最接近 3 米 5。
 *        你一手指向最矮的，一手指向最高的。加起来太矮，就把左手往右移（换高的）；
 *        太高，就把右手往左移（换矮的）。两只手相向而行，扫一遍就有答案。
 *
 * 复杂度：O(n^2)，比暴力 O(n^3) 快一个数量级。
 * ------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int target;
    cin >> target;

    vector<int> nums; // 用 vector：人数未知，读到 EOF 为止，自动扩容
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }

    int n = (int)nums.size();
    sort(nums.begin(), nums.end());

    // bestSum 记录"目前为止最接近的那个和"，bestGap 记录它与 target 的差距
    int bestSum = nums[0] + nums[1] + nums[2];
    int bestGap = abs(bestSum - target);

    for (int i = 0; i < n - 2; i++)
    {
        int L = i + 1;
        int R = n - 1;

        while (L < R)
        {
            int curSum = nums[i] + nums[L] + nums[R];
            int curGap = abs(curSum - target);

            // 发现了更接近的，就更新答案
            if (curGap < bestGap)
            {
                bestGap = curGap;
                bestSum = curSum;
            }

            // 根据大小关系移动指针
            if (curSum < target)
            {
                L++; // 和太小，左指针右移把和变大
            }
            else if (curSum > target)
            {
                R--; // 和太大，右指针左移把和变小
            }
            else
            {
                // 差距为 0，已经是完美答案，直接收工
                cout << curSum << endl;
                return 0;
            }
        }
    }

    cout << bestSum << endl;
    return 0;
}
