#include<iostream>
using namespace std;

class Cube
{
public:
	int getW()
	{
		return m_W;
	}
	void setW(int w)
	{
		m_W = w;
	}
	int getH()
	{
		return m_H;
	}
	void setH(int h)
	{
		m_H = h;
	}
	int getL()
	{
		return m_L;
	}
	void setL(int l)
	{
		m_L = l;
	}
	int calculateV()
	{
		return m_H * m_L * m_W;
	}
	int calculateS()
	{
		return 2 * m_H * m_L + 2 * m_H * m_W + 2 * m_L * m_W;
	}
	bool isSame(Cube& c)
	{
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}
private:
	int m_L;
	int m_H;
	int m_W;
};
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	return false;
}
int main()
{
	Cube c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);

	Cube c2;
	c2.setH(10);
	c2.setL(10);
	c2.setW(100);

	bool set = isSame(c1, c2);
	if (set)
	{
		cout << "全局函数判断： 立方体相等" << endl;
	}
	else
	{
		cout << "全局函数判断： 立方体不相等" << endl;

	}

	bool ret = c1.isSame(c2);
	if (ret)
	{
		cout << "全局函数判断： 立方体相等" << endl;
	}
	else
	{
		cout << "全局函数判断： 立方体不相等" << endl;

	}

	//system("pause");
	return 0;
}