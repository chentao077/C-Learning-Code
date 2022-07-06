#include<iostream>
using namespace std;

class Point
{
public:
	void setX(int x)
	{
		m_x = x;
	}
	void setY(int y)
	{
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};
class Circle
{
public:
	int getR() 
	{
		return m_r;
	}
	Point getCenter()
	{
		return m_center;
	}
	void setR(int r)
	{
		m_r = r;
	}
	void setCenter(Point center)
	{
		m_center = center;
	}
private:
	int m_r;
	Point m_center;
};
void Relation(Circle center,Point point)
{
	int distance =
		(center.getCenter().getX() - point.getX()) * (center.getCenter().getX() - point.getX())
		+ (center.getCenter().getY() - point.getY()) * (center.getCenter().getY() - point.getY());
	int r = (center.getR()) * (center.getR());
	if (r == distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (r < distance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
int main()
{
	//初始化圆类
	Circle c1;
	c1.setR(5);
	Point center;
	center.setX(5);
	center.setY(5);
	c1.setCenter(center);
	//初始化点
	Point point;
	point.setX(5);
	point.setY(11);
	//判断位置
	Relation(c1, point);
	return 0;
}