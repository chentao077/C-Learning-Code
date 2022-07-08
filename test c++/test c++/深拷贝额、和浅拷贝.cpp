#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person默认结构函数调用" << endl;
	}
	int m_age;
	int* m_height;
	Person(int age,int height)
	{
		cout << "Person有参结构函数调用" << endl;
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p)
	{
		cout << "Person拷贝函数调用" << endl;
		m_age = p.m_age;
		//m_height = height系统默认拷贝函数，会导致重复释放问题
		m_height = new int(*p.m_height);
	}
	
	~Person()
	{
		cout << "Person析构函数调用" << endl;
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
	}
};
int main()
{
	Person p1(18, 180);
	Person p2(p1);
	cout << "p1的年龄： " << p1.m_age << " p1的身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " p2的身高： " << *p2.m_height << endl;
	return 0;
}