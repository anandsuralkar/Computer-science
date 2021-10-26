#include<iostream>
using namespace std;
class demo
{
int a;
int b;
int *p;
public:
demo()
{
p= new int;
}
setdata(int x, int y, int z)
{
a=x;
b=y;
*p=z;
}
showdata()
{
cout<<"value of a is:"<<a<<endl;
cout<<"value of b is:"<<b<<endl;
cout<<"value of *p is:"<<*p<<endl;
cout<<"value of p is:"<<p<<endl;
}};
int main()
{
demo d1;
d1.setdata(4,5,10);
demo d2=d1;
d2.showdata();
return 0;
}
