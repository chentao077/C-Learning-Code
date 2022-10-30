#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	int id;
	string name;
	Student()
	{}
	Student(int tmp, string arr)
	{
		id = tmp;
		name = arr;
	}
};

class Teather
{
public:
	int id;
	string name;
	Teather()
	{}
	Teather(int tmp, string arr)
	{
		id = tmp;
		name = arr;
	}
};

class Graduate :public Student, public Teather
{
public:
	int id;
	string name;
	Graduate(int tmp1,int tmp2,int tmp3,string arr1,string arr2,string arr3):
		Student(tmp1,arr1),Teather(tmp2,arr2)
	{
		id = tmp3;
		name = arr3;
	}
};

int main()
{
	Student s1(12, "abd");
	Teather t1(233, "李四");
	Graduate g1(12,13,14,"acd","adcv","aaaa");
	cout << "研究生g1名字：" << g1.name << " id：" << g1.id << endl;
	return 0;
}