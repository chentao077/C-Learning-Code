#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "PersonĬ�Ͻṹ��������" << endl;
	}
	int m_age;
	int* m_height;
	Person(int age,int height)
	{
		cout << "Person�вνṹ��������" << endl;
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p)
	{
		cout << "Person������������" << endl;
		m_age = p.m_age;
		//m_height = heightϵͳĬ�Ͽ����������ᵼ���ظ��ͷ�����
		m_height = new int(*p.m_height);
	}
	
	~Person()
	{
		cout << "Person������������" << endl;
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
	cout << "p1�����䣺 " << p1.m_age << " p1����ߣ� " << *p1.m_height << endl;
	cout << "p2�����䣺 " << p2.m_age << " p2����ߣ� " << *p2.m_height << endl;
	return 0;
}