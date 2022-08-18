#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//文本写入
void test1()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();
}

//文本输出
void test2()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种打开方式
	/*char buf[1024];
	while (ifs >> buf)//一次读取一行
	{
		cout << buf << endl;
	}*/
	//第二种打开方式
	//char buf[1024];
	//while (ifs.getline(buf,sizeof(buf)))//一次读取一行，第一个参数为输出对象，第二个为读取的大小
	//{
	//	cout << buf << endl;
	//}
	//第三种打开方式
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//第四种打开方式
	char c;
	while ((c = ifs.get()) != EOF);//一次读取一个字
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