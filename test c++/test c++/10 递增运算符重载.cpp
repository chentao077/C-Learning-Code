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
	//��Ա����ʵ��
	//ǰ��++
	Myint& operator++()
	{
		m_int++;
		return *this;
	}
	//����++
	Myint operator++(int)//int ռλ������ǰ��++�ͺ���++
	{
		Myint tmp = *this;//��¼ԭ����ֵ�����ڷ���
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