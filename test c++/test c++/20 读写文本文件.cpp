#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//�ı�д��
void test1()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	ofs.close();
}

//�ı����
void test2()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ִ򿪷�ʽ
	/*char buf[1024];
	while (ifs >> buf)//һ�ζ�ȡһ��
	{
		cout << buf << endl;
	}*/
	//�ڶ��ִ򿪷�ʽ
	//char buf[1024];
	//while (ifs.getline(buf,sizeof(buf)))//һ�ζ�ȡһ�У���һ������Ϊ������󣬵ڶ���Ϊ��ȡ�Ĵ�С
	//{
	//	cout << buf << endl;
	//}
	//�����ִ򿪷�ʽ
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//�����ִ򿪷�ʽ
	char c;
	while ((c = ifs.get()) != EOF);//һ�ζ�ȡһ����
	{
		cout << c;
	}
	ifs.close();
}
int main()
{
	test1();
	test2();
	return 0;
}