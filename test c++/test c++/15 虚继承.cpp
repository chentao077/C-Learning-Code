#include<iostream>
using namespace std;

class Base
{
public:
	int m_Age;
};
//继承前加virtual关键字，变为虚继承
//此时公共父类Base称为虚基类
class son1 :virtual public Base {};
class son2 :virtual public Base {};
class tuo :public son1, son2 {};
int main()
{
	tuo tu;
	tu.m_Age = 10;
	cout << "m_Age=" << tu.m_Age << endl;
	return 0;


}