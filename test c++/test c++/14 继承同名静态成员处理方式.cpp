#include<iostream>
using namespace std;

//同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象和通过类名）
class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
	static int m_A;
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};
int Son::m_A = 200;

//同名成员属性
void test1()
{
	//通过对象访问
	cout << "通过对象访问" << endl;
	Son s1;
	cout << "Son下  m_A =" << s1.m_A << endl;
	cout << "Base下 m_A=" << s1.Base::m_A << endl;

	//通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son下  m_A =" << Son::m_A << endl;
	cout << "Base下 m_A=" << Son::Base::m_A << endl;
}

//同名成员函数
void test2()
{
	//通过对象访问
	cout << "通过对象访问" << endl;
	Son s2;
	s2.func();
	s2.Base::func();

	//通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作用域访问
	//即不能重载
	Son::Base::func(10);
}
int main()
{
	test1();
	test2();
	return 0;
}