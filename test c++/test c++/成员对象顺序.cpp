#include<iostream>
#include<string>
using namespace std;
class Phone
{
public:
	Phone(string name)
	{
		cout << "Phone�вι��캯������" << endl;
		m_Pname = name;
	}
	~Phone()
	{
		cout << "Phone������������" << endl;

	}
	string m_Pname;
};
class person
{
public:
	person(string name, string Pname):m_name(name),m_phone(Pname)
	{
		cout << "Person���캯������" << endl;
	}
	~person()
	{
		cout << "Person������������" << endl;

	}
	void play()
	{
		cout << m_name << "ʹ��" << m_phone.m_Pname << endl;
	}
	string m_name;
	Phone m_phone;
};
int main()
{
	//�����˳���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//������˳���෴
	person p1("����","ƻ��");
	p1.play();
	return 0;
}