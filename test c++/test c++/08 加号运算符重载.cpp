#include<iostream>
using namespace std;

//�Ӻ����������
class Person1
{
public:
	Person1()
	{

	}
	Person1(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	int m_A;
	int m_B;
	//��Ա����ʵ�ּӺ����������
	Person1 operator+(const Person1& p)
	{
		Person1 tmp;
		tmp.m_A = this->m_A + p.m_A;
		tmp.m_B = this->m_B + p.m_B;
		return tmp;
	}
};
//ȫ�ֺ���ʵ�ּӺ����������
Person1 operator+(const Person1& p1, const Person1& p2)
{
	Person1 tmp;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_B + p2.m_B;
	return tmp;
}
//��������ؿ��Է�����������
Person1 operator+(const Person1& p1, int val)
{
	Person1 tmp;
	tmp.m_A = p1.m_A + val;
	tmp.m_B = p1.m_B + val;
	return tmp;
}
void test()
{
	Person1 p1(10, 10);
	Person1 p2(10, 10);

	//��Ա������ʽ
	Person1 p3 = p1 + p2;//�൱��p2.operaor+(p1)
	cout << "m_A:" << p3.m_A << " m_B:" << p3.m_B << endl;
	//ȫ�ֺ�����ʽ
	Person1 p4 = p1 + 10;//�൱��operaor+��p1,10��
	cout << "m_A:" << p4.m_A << " m_B:" << p4.m_B << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}