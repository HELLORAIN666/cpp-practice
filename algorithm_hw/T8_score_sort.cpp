/*
 * T8 成绩排序（结构体数组与指针的使用）
 * ------------------------------------------------------------
 * 思路：
 *   1. 一个学生有"名字"和"分数"两个属性，类型不同 → 用 struct 打包成一个整体。
 *      比喻：struct 就是一个"快递盒"，把零散的东西打包成一个包裹，方便整体搬运、排序。
 *   2. 排序规则是复合的（先比分数，再比名字）→ 写一个比较函数告诉 sort "什么叫前一个更靠前"。
 *   3. 用指针访问结构体成员要用 -> （箭头），等价于 (*p).成员。
 *      比喻：p 是门牌号，(*p).name 是"先找到房子再拿东西"，p->name 是同一件事的简写。
 *
 * 【提高部分】（已实现，见下面 cmpByScore / cmpByName / 函数指针注册表）
 *   sort 的第三个参数可以传函数指针，于是"按什么排"就变成了一个可插拔的零件。
 * ------------------------------------------------------------
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student
{
    string name;
    int score;
};

// 排序规则：分数高的在前；分数相同，名字字典序小的在前
bool cmpByScore(const Student &a, const Student &b)
{
    if (a.score != b.score)
    {
        return a.score > b.score; // 降序
    }
    return a.name < b.name;       // string 的 < 就是字典序比较
}

// 备用规则：只按名字字典序排
bool cmpByName(const Student &a, const Student &b)
{
    return a.name < b.name;
}

int main()
{
    int n;
    cin >> n;

    Student *stu = new Student[n]; // 动态数组，用指针管理

    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].score;
    }

    // ===== 演示指针访问结构体：(stu + i) 就是第 i 个元素的地址 =====
    // for (int i = 0; i < n; i++)
    // {
    //     cout << (stu + i)->name << " " << (stu + i)->score << endl;
    // }

    sort(stu, stu + n, cmpByScore);

    for (int i = 0; i < n; i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }

    delete[] stu; // new[] 出来的必须 delete[] 还回去，否则内存泄漏
    return 0;
}

/* ============================================================
 * 【提高】函数指针 + 枚举：实现"按各种方式排序"的注册机制
 * ------------------------------------------------------------
 * 思路：把"比较规则"这件事也做成一个数据 —— 函数指针。
 *   比较函数的类型是：bool (*)(const Student&, const Student&)
 *   用 typedef 起个短名字 CompareFunc，然后像存变量一样存进数组。
 *   运行时想换排序方式，只要改 type（枚举）就行，不用改排序代码。
 *   这就是"策略模式"的 C 语言写法，在嵌入式里极其常见（回调函数的雏形）。
 * ============================================================ */

typedef bool (*CompareFunc)(const Student &, const Student &);

enum SortType
{
    BY_SCORE = 0, // 按成绩
    BY_NAME,      // 按名字
    TYPE_COUNT    // 技巧：放最后，它的值正好是"一共有几种方式"
};

// 函数指针表：下标就是枚举值
CompareFunc Data_Process[TYPE_COUNT] = { cmpByScore, cmpByName };

// 注册函数：把某个处理函数挂到某个枚举位上
void Function_Register(CompareFunc Data_Process_Func, SortType type)
{
    Data_Process[type] = Data_Process_Func;
}

/*
 * 使用示例（取消注释即可试）：
 *   Function_Register(cmpByName, BY_SCORE);   // 把 0 号位置换成按名字排
 *   sort(stu, stu + n, Data_Process[BY_SCORE]);
 */
