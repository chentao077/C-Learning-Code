#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal 构造函数调用" << endl;
	}
	virtual void speak() = 0;
	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal析构函数调用" << endl;
	//}
	//纯虚析构函数 类内初始化
	virtual ~Animal() = 0;
};
//类外声明
Animal::~Animal()
{
	cout << "Animal纯析构函数调用" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat 构造函数调用" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	~Cat()
	{
		cout << "Cat 析构函数调用" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};
void test()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//虚析构函数就是用来解决通过父类指针释放子类对象
	animal = NULL;
}
int main()
{
	test();
	return 0;
}