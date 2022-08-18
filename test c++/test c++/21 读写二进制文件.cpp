#include<iostream>
#include<fstream>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//������д��
void test1()
{
	ofstream ofs("Person.txt", ios::out | ios::binary);
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

//�����ƶ��ļ�
void test2()
{
	ifstream ifs("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
}
int main()
{
	test1();
	test2();
	return 0;
}