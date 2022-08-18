#include<iostream>
using namespace std;

//����������Ʒ
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//�涨����
	void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class coffee :public AbstractDrinking
{
public:
	void Boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "�����ȵ��뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "����ţ�̺Ϳ���" << endl;
	}
};

//������ˮ
class tea :public AbstractDrinking
{
public:
	void Boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "����Ҷ���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "��������" << endl;
	}
};

//��������
void dowork(AbstractDrinking* p)
{
	p->MakeDrink();
	delete p;
}

void test()
{
	dowork(new coffee);
	cout << "--------------------" << endl;
	dowork(new tea);
}

int main()
{
	test();
	return 0;
}