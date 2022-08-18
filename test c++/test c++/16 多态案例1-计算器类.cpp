#include<iostream>
#include<string>
using namespace std;

//��ͨʵ��
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
	//����ṩ�µļ�����Ҫ�޸�Դ��
	int m_A;
	int m_B;
};
void test1()
{
	//��ͨʵ�ֲ���
	Calculator c;
	c.m_A = 10;
	c.m_B = 10;
	cout << c.m_A << "+" << c.m_B << "=" << c.get("+") << endl;
	cout << c.m_A << "-" << c.m_B << "=" << c.get("-") << endl;
	cout << c.m_A << "*" << c.m_B << "=" << c.get("*") << endl;
}
//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
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
//�ӷ�������
class AddCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A + m_B;
	}
};
//����������
class SubCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A - m_B;
	}
};
//�˷�������
class MulCalculator :public AbstractCalculator
{
	int get()
	{
		return m_A * m_B;
	}
};
void test2()
{
	//�����ӷ�������
	AbstractCalculator* abc = new AddCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "+" << abc->m_B << "=" << abc->get() << endl;
	delete abc;//��������
	//��������������
	abc = new SubCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "-" << abc->m_B << "=" << abc->get() << endl;
	delete abc;
	//�����˷�������
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