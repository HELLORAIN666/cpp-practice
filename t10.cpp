#include<iosream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int id;
    double price;
    int stock;

public:
Book()
{
    title = "";
    author = "";
    id = 0;
    price = 0.0;
    stock = 0;
}

Book(string t, string a, int i, double p, int s)
{
    title = t;
    author = a;
    id = i;
    price = p;
    stock = s;
}

~Book()
{ 

}//对象销毁时使用

int getTitle() const
{
    return title;
}

int getId() const
{
    return id;
}

void