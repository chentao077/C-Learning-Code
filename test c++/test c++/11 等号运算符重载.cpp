#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person &p);
	friend void test();
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	Person& operator=(Person& p)
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		return *this;
	}
private:
	int* m_age;
};
ostream& operator<<(ostream& cout, Person &p)
{
	cout << p.m_age;
	return cout;
}
void test()
{
	Person p1(10);
	Person p2(20);
	Person p3(30);
	//p2 = p1;
	//�����ṩ����ǳ������������ڴ��ظ��ͷ�
	p3 = p2 = p1;
	//����
	//p3.operator=(p2.operator=(p1));
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;
	cout << "p3:" << p3 << endl;
	cout << "p1:" << *p1.m_age << endl;
	cout << "p2:" << *p2.m_age << endl;
	cout << "p3:" << *p3.m_age << endl;
}
int main()
{
	test();
	return 0;
}