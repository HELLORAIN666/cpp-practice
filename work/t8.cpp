#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
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
    return a.name < b.name; // string 的 < 就是字典序比较
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

    sort(stu, stu + n, cmpByScore);

    for (int i = 0; i < n; i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }

    delete[] stu; // new[] 出来的必须 delete[] 还回去，否则内存泄漏
    return 0;
}

typedef bool (*CompareFunc)(const Student &, const Student &);

enum SortType
{
    BY_SCORE = 0, // 按成绩
    BY_NAME,      // 按名字
    TYPE_COUNT
};

// 函数指针表：下标就是枚举值
CompareFunc Data_Process[TYPE_COUNT] = {cmpByScore, cmpByName};

// 注册函数：把某个处理函数挂到某个枚举位上
void Function_Register(CompareFunc Data_Process_Func, SortType type)
{
    Data_Process[type] = Data_Process_Func;
}
