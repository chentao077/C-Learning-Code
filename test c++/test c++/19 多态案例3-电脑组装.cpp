#include<iostream>
#include<string>
using namespace std;

//抽象CPU类
class CPU
{
public:
	virtual void calculate() = 0;
};

//抽象显卡类
class GPU
{
public:
	virtual void display() = 0;
};

//抽象内存条
class ROW
{
public:
	virtual void storage() = 0;
};

//抽象电脑类
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, ROW* row)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_row = row;
	}

	//工作函数
	void work()
	{
		m_cpu->calculate();
		m_gpu->display();
		m_row->storage();
	}

	//提供析构函数 释放三个零件
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

//具体厂商
//Intel厂商
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel的GPU开始计算了" << endl;
	}
};

class IntelROW :public ROW
{
public:
	void storage()
	{
		cout << "Intel的内存开始计算了" << endl;
	}
};

//AMD厂商
class AMDCPU :public CPU
{
public:
	void calculate()
	{
		cout << "AMD的CPU开始计算了" << endl;
	}
};

class AMDGPU :public GPU
{
public:
	void display()
	{
		cout << "AMD的GPU开始计算了" << endl;
	}
};

class AMDROW :public ROW
{
public:
	void storage()
	{
		cout << "AMD的内存开始计算了" << endl;
	}
};

void test()
{
	//第一台电脑零件
	CPU* Intelcpu = new IntelCPU;
	GPU* Intelgpu = new IntelGPU;
	ROW* Intelrow = new IntelROW;

	cout << "第一台电脑开始工作" << endl;
	//创建第一台电脑
	Computer* computer1 = new Computer(Intelcpu, Intelgpu, Intelrow);
	computer1->work();
	delete computer1;
	computer1 = NULL;

	cout << "-------------------------" << endl;
	cout << "第二台电脑开始工作" << endl;
	//创建第二台电脑
	Computer* computer2 = new Computer(new AMDCPU, new AMDGPU, new AMDROW);
	computer2->work();
	delete computer2;
	computer2 = NULL;

	cout << "-------------------------" << endl;
	cout << "第三台电脑开始工作" << endl;
	//创建第三台电脑
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