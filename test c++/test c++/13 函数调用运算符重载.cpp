#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
void test1()
{
	//重载的（）操作符 也称为仿函数
	MyPrint myprint;
	myprint("hello word");
}
class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
void test2()
{
	MyAdd myadd;
	int a = myadd(10, 10);
	cout << a << endl;
	//匿名对象调用
	cout << MyAdd()(10, 10) << endl;
}
int main()
{
	test1();
	test2();
	return 0;
}