#include<iostream>
#include<string>
using namespace std;
const double PI = 3.14;
class Circle
{
//����Ȩ��
public:
	//����
	int m_r;
	//��Ϊ
	double perimeter()
	{
		//��ȡԲ���ܳ�
		return 2 * PI * m_r;
	}
};
class Student
{
public:
	//����
	string m_name;
	int m_id;
	void showStudent()
	{
		cout << "������ " << m_name << " ѧ�ţ� " << m_id<<endl;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setId(int id)
	{
		m_id = id;
	}
};
class People
{
public:
	//д����
	void setname(string name)
	{
		m_name = name;
	}
	//������
	string getname()
	{
		return m_name;
	}
	//д����
	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "�������" << endl;
			m_age = 0;
			return;
		}
		m_age = age;
	}
	//������
	int getage()
	{
		return m_age;
	}
	void setlover(string lover)
	{
		m_lover = lover;
	}

private:
	string m_name;//�ɶ���д
	int m_age;//�ɶ���д
	string m_lover;//��д
};
int main()
{
	Circle c1;//�����������  c1
	c1.m_r = 10;//������İ뾶��ֵ
	cout << "Բ���ܳ�Ϊ�� " << c1.perimeter() << endl;




	Student s1;
	s1.m_name = "����";
	s1.m_id = 1;
	s1.showStudent();
	Student s2;
	s2.setName("����");
	s2.setId(2);
	s2.showStudent();
	



	People p1;
	p1.setage(100);//��������
	p1.setname("����");//��������
	p1.setlover("abc");
	cout << "������" << p1.getname() << " ����" << p1.getage() << endl;
	system("pause");
	return 0;
}