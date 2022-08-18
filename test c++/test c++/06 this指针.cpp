#include<iostream>
using namespace std;

class Person
{
public:
	//当形参和成员变量同名时，可以用this指针区分
	Person(int age)
	{
		this->age = age;
	}
	Person& ageAdd(Person& p)
	{
		this->age += p.age;
		//返回对象本身
		return *this;
	}
	int age;
};
int main()
{
	Person p1(10);
	Person p2(10);
	p2.ageAdd(p1).ageAdd(p1).ageAdd(p1);
	cout << "p2的年龄是： " << p2.age << endl;

	return 0;
}