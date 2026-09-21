#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
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
                cout << curSum << endl;
                return 0;
            }
        }
    }

    cout << bestSum << endl;
    return 0;
}
