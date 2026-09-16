#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
    //获取年龄
    int getAge()
    {
        return age;
    }
    //设置年龄0到150；
    void setAge(int a)
    {
        if(a>=0 && a<=150)
        {
            age = a;
        }
        else
        {
            cout<<"年龄必须在0到150之间"<<endl;
        }

    }



    void setIdol(string i)
    {
        idol = i;
    }



private:
    string name;//可读可写

    int age = 18;//只读，注意，一定要默认一个具体年龄，不然只会读出一个乱码；只读也可以写（年龄必须在0到150之间）

    string idol;//只写

};

int main()
{

    Person p;
    p.setName("John");
    cout<<"Name: " << p.getName() << endl; 
    p.setAge(18);
    //p.age =20
    //获取年龄
    cout<<"Age: " << p.getAge() << endl;//只读状态，没法写

    p.setIdol("Taylor Swift");//只写状态外界访问不到
    //cout<<"Idol: " << p.getIdol() << endl;

    return 0;
}