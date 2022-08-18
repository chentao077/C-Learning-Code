#include<iostream>
#include<fstream>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//二进制写入
void test1()
{
	ofstream ofs("Person.txt", ios::out | ios::binary);
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

//二进制读文件
void test2()
{
	ifstream ifs("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}
int main()
{
	test1();
	test2();
	return 0;
}