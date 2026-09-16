#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int num = a*10+b; //将元角换算成角
    const int price = 19; //一支笔19角

    cout<<num/price<<endl; //整数除法，自动向下取整

    return 0;
}