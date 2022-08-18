#include<iostream>
#include<string>
using namespace std;

//普通实现
class Calculator
{
public:
	int get(string oper)
	{
		if (oper == "+")
		{
			return m_A + m_B;
		}
		else if (oper == "-")
		{
			return m_A - m_B;
		}
		else if (oper == "*")
		{
			return m_A * m_B;
		}
	}
	//如果提供新的计算需要修改源码
	int m_A;
	int m_B;
};
void test1()
{
	//普通实现测试
	Calculator c;
	c.m_A = 10;
	c.m_B = 10;
	cout << c.m_A << "+" << c.m_B << "=" << c.get("+") << endl;
	cout << c.m_A << "-" << c.m_B << "=" << c.get("-") << endl;
	cout << c.m_A << "*" << c.m_B << "=" << c.get("*") << endl;
}
//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator
{
public:
	virtual int get()
	{
		return 0;
	}
	int m_A;
	int m_B;
};
//加法计算器
class AddCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A + m_B;
	}
};
//减法计算器
class SubCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A - m_B;
	}
};
//乘法计算器
class MulCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A * m_B;
	}
};
void test2()
{
	//创建加法计算器
	AbstractCalculator* abc = new AddCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "+" << abc->m_B << "=" << abc->get() << endl;
	delete abc;//用完销毁
	//创建减法计算器
	abc = new SubCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "-" << abc->m_B << "=" << abc->get() << endl;
	delete abc;
	//创建乘法计算器
	abc = new MulCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "*" << abc->m_B << "=" << abc->get() << endl;
	delete abc;
}
int main()
{
	test1();
	test2();
	return 0;
}