#include<string.h>
#include<iostream>
using namespace std;

template<class T1, class T2>
class person
{
public:
	//��Ա������������
	person(T1 age, T2 name);
	void showperson();
	T1 m_age;
	T2 m_name;
};

//���캯������ʵ��
template<class T1,class T2>
person<T1, T2>::person(T1 age, T2 name)
{
	this->m_age = age;
	this->m_name = name;
}

//��Ա��������ʵ��
template<class T1, class T2>
void person<T1, T2>::showperson()
{
	cout << "������ " << this->m_name << " ���䣺" << this->m_age << endl;
}

void test1()
{
	person<string, int>p("Tom", 20);
	p.showperson();
}
int main()
{
	test1();
	system("pause");
	return 0;
}