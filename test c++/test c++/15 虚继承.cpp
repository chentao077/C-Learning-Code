#include<iostream>
using namespace std;

class Base
{
public:
	int m_Age;
};
//�̳�ǰ��virtual�ؼ��֣���Ϊ��̳�
//��ʱ��������Base��Ϊ�����
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