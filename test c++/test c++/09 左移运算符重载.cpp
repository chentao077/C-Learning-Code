#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//��Ա����ʵ�ֲ���
private:
	int m_A;
	int m_B;
};
ostream& operator<<(ostream& cout, Person& p)
{
	cout << "a:" << p.m_A << " b:" << p.m_B;
	return cout;
}
void test()
{
	Person p1(10, 20);
	cout << p1 << "hello word" << endl;//����ֵ��cout��������ʽ���
}
int main()
{
	test();
	return 0;
}