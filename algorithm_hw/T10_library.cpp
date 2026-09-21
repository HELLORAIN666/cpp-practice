/*
 * T10 图书管理系统（类的使用）
 * ------------------------------------------------------------
 * 设计思路：把"现实世界"翻译成"代码世界"
 *
 *   现实            代码
 *   ----------      ---------------------------
 *   一本书           Book 类的一个对象（成员变量 = 属性，成员函数 = 行为）
 *   图书馆           Library 类的一个对象（持有 vector<Book>，提供增删改查）
 *
 * 为什么要分两个类？（单一职责原则）
 *   Book 只管"我自己是什么"：我的书名、我的库存够不够。
 *   Library 只管"怎么管这一堆书"：怎么找、怎么排序、怎么增删。
 *   如果全塞进一个 main 函数里，代码马上变成一坨谁也不敢碰的面条。
 *
 * 封装（encapsulation）的意义：
 *   成员变量设成 private，外部不许直接改 stock = -100 这种脏操作，
 *   只能通过 borrow() 这种"正规窗口"办事，窗口里能做合法性检查。
 *   比喻：银行柜台。你不能自己进金库拿钱，只能在窗口办业务，柜员会查你的身份证。
 *
 * 关于构造函数：
 *   对象"出生"时必须被正确初始化，否则成员变量是随机垃圾值。
 *   构造函数就是"出生证明 + 初始配置"，在对象创建的瞬间自动调用一次。
 * ------------------------------------------------------------
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// ===================== Book 类：一本书 =====================
class Book
{
private:
    string title;
    string author;
    int id;
    double price;
    int stock;

public:
    // 默认构造：给一个"空书"的合法状态
    Book()
    {
        title = "";
        author = "";
        id = 0;
        price = 0.0;
        stock = 0;
    }

    // 带参构造：创建时直接把信息填好（推荐写法，避免"先空着再一个个赋值"）
    Book(string t, string a, int i, double p, int s)
    {
        title = t;
        author = a;
        id = i;
        price = p;
        stock = s;
    }

    // 析构函数：对象销毁时自动调用。这里没有动态内存，所以是空的
    ~Book()
    {
    }

    // --- getter：只读窗口，让外部能"看"但不能"改" ---
    int getId() const
    {
        return id;
    }

    string getTitle() const
    {
        return title;
    }

    // --- 行为：库存相关的正规操作 ---
    bool borrowOne()
    {
        if (stock <= 0)
        {
            return false; // 库存不足，拒绝
        }
        stock--;
        return true;
    }

    void returnOne()
    {
        stock++;
    }

    // 按格式输出一行图书信息
    void print() const
    {
        cout << "ID:" << id
             << ", Title:" << title
             << ", Author:" << author
             << ", Price:" << fixed << setprecision(2) << price
             << ", Stock:" << stock << endl;
    }

    // --- 运算符重载（加分项）---

    // == ：两本书"相等"定义为编号相同（因为编号才是唯一身份证）
    bool operator==(const Book &other) const
    {
        return this->id == other.id;
    }

    // < ：按编号升序，这样 sort 就能直接对 Book 排序，不用再写比较函数
    bool operator<(const Book &other) const
    {
        return this->id < other.id;
    }
};

// ===================== Library 类：图书馆 =====================
class Library
{
private:
    vector<Book> books; // 用 vector 存书：自动扩容，不用操心数组大小

public:
    Library()
    {
    }

    ~Library()
    {
    }

    // 1. 添加图书：先查重，编号已存在就拒绝
    bool addBook(const Book &b)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getId() == b.getId())
            {
                return false; // 编号重复
            }
        }
        books.push_back(b);
        return true;
    }

    // 2. 删除图书：按编号找，找到了用 erase 抹掉
    bool deleteBook(int id)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getId() == id)
            {
                books.erase(books.begin() + i); // 删除后，后面的元素会自动前移
                return true;
            }
        }
        return false;
    }

    // 3. 借阅：返回 0=成功 1=没这本书 2=没库存（用状态码区分两种失败）
    int borrowBook(int id)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getId() == id)
            {
                if (books[i].borrowOne())
                {
                    return 0;
                }
                return 2;
            }
        }
        return 1;
    }

    // 4. 归还：题目说明无需检查编号是否存在
    void returnBook(int id)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getId() == id)
            {
                books[i].returnOne();
                return;
            }
        }
        // 没找到也什么都不做，主函数照样输出 Return success!
    }

    // 5. 显示所有图书：按编号升序（先排序再输出）
    void showBooks()
    {
        if (books.empty())
        {
            cout << "No books!" << endl;
            return;
        }
        sort(books.begin(), books.end()); // 依赖 Book 重载的 operator<
        for (int i = 0; i < (int)books.size(); i++)
        {
            books[i].print();
        }
    }

    // 6. 查询：按书名精确匹配
    bool searchBook(const string &t, Book &out) const
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getTitle() == t)
            {
                out = books[i];
                return true;
            }
        }
        return false;
    }
};

// ===================== 主函数：负责"读指令 - 分发 - 打印" =====================
int main()
{
    int n;
    cin >> n;

    Library lib;

    for (int k = 0; k < n; k++)
    {
        string op;
        cin >> op;

        if (op == "add")
        {
            string title, author;
            int id, stock;
            double price;
            cin >> title >> author >> id >> price >> stock;

            Book b(title, author, id, price, stock);
            if (lib.addBook(b))
            {
                cout << "Book added successfully!" << endl;
            }
            else
            {
                cout << "Book ID already exists!" << endl;
            }
        }
        else if (op == "delete")
        {
            int id;
            cin >> id;
            if (lib.deleteBook(id))
            {
                cout << "Book deleted successfully!" << endl;
            }
            else
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (op == "borrow")
        {
            int id;
            cin >> id;
            int ret = lib.borrowBook(id);
            if (ret == 0)
            {
                cout << "Borrow success!" << endl;
            }
            else if (ret == 2)
            {
                cout << "Out of stock!" << endl;
            }
            else
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (op == "return")
        {
            int id;
            cin >> id;
            lib.returnBook(id);
            cout << "Return success!" << endl;
        }
        else if (op == "show")
        {
            lib.showBooks();
        }
        else if (op == "search")
        {
            string title;
            cin >> title;
            Book result;
            if (lib.searchBook(title, result))
            {
                result.print();
            }
            else
            {
                cout << "Book not found!" << endl;
            }
        }
    }

    return 0;
}
