#include<iostream>
using namespace std;

class Person
{
public:
	//���βκͳ�Ա����ͬ��ʱ��������thisָ������
	Person(int age)
	{
		this->age = age;
	}
	Person& ageAdd(Person& p)
	{
		this->age += p.age;
		//���ض�����
		return *this;
	}
	int age;
};
int main()
{
	Person p1(10);
	Person p2(10);
	p2.ageAdd(p1).ageAdd(p1).ageAdd(p1);
	cout << "p2�������ǣ� " << p2.age << endl;

	return 0;
}