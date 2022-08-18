#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal ���캯������" << endl;
	}
	virtual void speak() = 0;
	//������������virtual�ؼ��֣��������������
	//virtual ~Animal()
	//{
	//	cout << "Animal������������" << endl;
	//}
	//������������ ���ڳ�ʼ��
	virtual ~Animal() = 0;
};
//��������
Animal::~Animal()
{
	cout << "Animal��������������" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat ���캯������" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}
	~Cat()
	{
		cout << "Cat ������������" << endl;
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
	//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//���������������������ͨ������ָ���ͷ��������
	animal = NULL;
}
int main()
{
	test();
	return 0;
}