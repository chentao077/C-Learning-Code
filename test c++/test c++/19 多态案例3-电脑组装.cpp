#include<iostream>
#include<string>
using namespace std;

//����CPU��
class CPU
{
public:
	virtual void calculate() = 0;
};

//�����Կ���
class GPU
{
public:
	virtual void display() = 0;
};

//�����ڴ���
class ROW
{
public:
	virtual void storage() = 0;
};

//���������
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, ROW* row)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_row = row;
	}

	//��������
	void work()
	{
		m_cpu->calculate();
		m_gpu->display();
		m_row->storage();
	}

	//�ṩ�������� �ͷ��������
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_row != NULL)
		{
			delete m_row;
			m_row = NULL;
		}
	}
private:
	CPU* m_cpu;
	GPU* m_gpu;
	ROW* m_row;
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};

class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel��GPU��ʼ������" << endl;
	}
};

class IntelROW :public ROW
{
public:
	void storage()
	{
		cout << "Intel���ڴ濪ʼ������" << endl;
	}
};

//AMD����
class AMDCPU :public CPU
{
public:
	void calculate()
	{
		cout << "AMD��CPU��ʼ������" << endl;
	}
};

class AMDGPU :public GPU
{
public:
	void display()
	{
		cout << "AMD��GPU��ʼ������" << endl;
	}
};

class AMDROW :public ROW
{
public:
	void storage()
	{
		cout << "AMD���ڴ濪ʼ������" << endl;
	}
};

void test()
{
	//��һ̨�������
	CPU* Intelcpu = new IntelCPU;
	GPU* Intelgpu = new IntelGPU;
	ROW* Intelrow = new IntelROW;

	cout << "��һ̨���Կ�ʼ����" << endl;
	//������һ̨����
	Computer* computer1 = new Computer(Intelcpu, Intelgpu, Intelrow);
	computer1->work();
	delete computer1;
	computer1 = NULL;

	cout << "-------------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	//�����ڶ�̨����
	Computer* computer2 = new Computer(new AMDCPU, new AMDGPU, new AMDROW);
	computer2->work();
	delete computer2;
	computer2 = NULL;

	cout << "-------------------------" << endl;
	cout << "����̨���Կ�ʼ����" << endl;
	//��������̨����
	Computer* computer3 = new Computer(new AMDCPU, new IntelGPU, new AMDROW);
	computer3->work(); 
	delete computer3;
	computer3 = NULL;
}
int main()
{
	test();
	return 0;
}