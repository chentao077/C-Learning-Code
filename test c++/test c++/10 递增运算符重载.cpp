#include<iostream>
using namespace std;

class Myint
{
	friend ostream& operator<<(ostream& cout, Myint p);
public:
	Myint()
	{
		m_int = 0;
	}
	//成员函数实现
	//前置++
	Myint& operator++()
	{
		m_int++;
		return *this;
	}
	//后置++
	Myint operator++(int)//int 占位符区分前置++和后置++
	{
		Myint tmp = *this;//记录原来的值，用于返回
		m_int++;
		return tmp;
	}
private:
	int m_int;
};
ostream& operator<<(ostream& cout, Myint p)
{
	cout << p.m_int;
	return cout;
}
void test1()
{
	Myint myint;
	cout << ++myint << endl;
	cout << myint << endl;
}
void test2()
{
	Myint myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}