#include<iostream>
using namespace std;
const float pi = 3.14;

class Graphical
{
public:
	virtual float area() = 0;
};

class Circle :public Graphical
{
private:
	int r;
public:
	Circle(int a)
	{
		r = a;
	}
	virtual float area()
	{
		return pi * r * r;
	}
};

class Rectangle :public Graphical
{
private:
	int w;
	int h;
public:
	Rectangle(int a, int b)
	{
		w = a;
		h = b;
	}
	virtual float area()
	{
		return w * h;
	}
};
class Triangle :public Graphical
{
private:
	int w;
	int h;
public:
	Triangle(int a, int b)
	{
		w = a;
		h = b;
	}
	virtual float area()
	{
		return w * h / 2;
	}
};
int main()

{
	Graphical* g1 = new Circle(3);
	Graphical* g2 = new Rectangle(3, 2);
	Graphical* g3 = new Triangle(3, 2);
	cout << "×ÜÃæ»ý£º" << g1->area() + g2->area() + g3->area() << endl;
	return 0;
}