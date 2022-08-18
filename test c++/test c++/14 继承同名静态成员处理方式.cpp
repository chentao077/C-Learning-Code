#include<iostream>
using namespace std;

//ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ�������ͨ��������
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

//ͬ����Ա����
void test1()
{
	//ͨ���������
	cout << "ͨ���������" << endl;
	Son s1;
	cout << "Son��  m_A =" << s1.m_A << endl;
	cout << "Base�� m_A=" << s1.Base::m_A << endl;

	//ͨ����������
	cout << "ͨ����������" << endl;
	cout << "Son��  m_A =" << Son::m_A << endl;
	cout << "Base�� m_A=" << Son::Base::m_A << endl;
}

//ͬ����Ա����
void test2()
{
	//ͨ���������
	cout << "ͨ���������" << endl;
	Son s2;
	s2.func();
	s2.Base::func();

	//ͨ����������
	cout << "ͨ����������" << endl;
	Son::func();
	Son::Base::func();
	//����ͬ������������ص�����������ͬ����Ա��������Ҫ�����������
	//����������
	Son::Base::func(10);
}
int main()
{
	test1();
	test2();
	return 0;
}