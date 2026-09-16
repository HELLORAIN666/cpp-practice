#include<iostream>
using namespace std;
#include<string>

class Person
{
public:

    Person()
    {
        cout<<"Person的无参构造函数的调用"<<endl;
    }
public:    
    Person(int a)
    {
        age = a;
        cout<<"Person的有参构造函数的调用"<<endl;
    }

    ~Person()
    {
        cout<<"Person的析构函数的调用"<<endl;
    }

    //拷贝构造函数
   Person(const Person& p)
   {
    age = p.age;
    cout<<"拷贝构造函数的调用"<<endl;
    
   }
    int age;


};

void test01()
{
    //括号法
    //Person p1;
    //Person p2(10);
    //Person p3(p2);

    //注意事项：调用默认构造函数时，不要加（）

    //cout<<"p2的年龄为:"<<p2.age<<endl;
    //cout<<"p3的年龄为:"<<p3.age<<endl;
    //显示法
    Person p1;
    Person p2 = Person(10);
    Person p3 = Person(p2);

    //Person(10);匿名对象 当前执行结束后，系统立即回收
    //cout<<"aaaa"<<endl;



    //隐式转换法
    Person p4 = 10;//相当于Person p4 = Person（10）；
    Person p5 = p4;//拷贝构造


}

int main()
{
    test01();

    system("pause");

    return 0;
}