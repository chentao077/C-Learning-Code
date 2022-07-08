#include<iostream>
#include<string>
using namespace std;
class Phone
{
public:
	Phone(string name)
	{
		cout << "Phone有参构造函数调用" << endl;
		m_Pname = name;
	}
	~Phone()
	{
		cout << "Phone析构函数调用" << endl;

	}
	string m_Pname;
};
class person
{
public:
	person(string name, string Pname):m_name(name),m_phone(Pname)
	{
		cout << "Person构造函数调用" << endl;
	}
	~person()
	{
		cout << "Person析构函数调用" << endl;

	}
	void play()
	{
		cout << m_name << "使用" << m_phone.m_Pname << endl;
	}
	string m_name;
	Phone m_phone;
};
int main()
{
	//构造的顺序：先调用对象成员的构造，再调用本类构造
	//析构的顺序相反
	person p1("张三","苹果");
	p1.play();
	return 0;
}