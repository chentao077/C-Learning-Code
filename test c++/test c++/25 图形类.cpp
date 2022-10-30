#include <iostream>
#include<math.h>
using namespace std;
const float pi = 3.14;
//点类
class Point
{
private:
    float x, y;
public:
    Point(float a, float b)
    {
        x = a; y = b;
    }
    virtual float area() { return 0.0; }
    virtual float volume() { return 0.0; }
};

//圆类
class Circle :public Point
{
protected:
    float r;
public:
    Circle(float a, float b, float c) :Point(a, b)
    {
        r = c;
    }
    float area() { return pi * r * r; }
    float volume() { return 0.0; }
};

//圆柱类
class Cylinder :public Circle
{
protected:
    float h;
public:
    Cylinder(float a, float b, float c, float d) :Circle(a, b, c)
    {
        h = d;
    }
    float area() { return (2 * pi * r * r + 2 * pi * r * h); }
    float volume() { return Circle::area() * h; }
};

//圆锥类
class Cone :public Circle
{
protected:
    float h;//高
    float l;
public:
    Cone(float a, float b, float c, float d) :Circle(a, b, c)
    {
        h = d;
        l = sqrt(h * h + r * r);
    }
  
    float area() { return (pi * r * l + Circle::area()); }
    float volume() { return Circle::area() * h / 3; }
};
//矩形类
class Rectangle :public Point
{
protected:
    float l;
    float w;
public:
    Rectangle(float a, float b, float c,float d) :Point(a, b)
    {
        l = c;
        w = d;  
    }
    float area() { return l * w; }
    float volume() { return 0.0; }
};

//长方体类
class Box :public Rectangle
{
protected:
    float h;
public:
    Box(float a, float b, float c, float d, float e) :Rectangle(a, b, c, d)
    {
        h = e;
    }
    float area() { return 2 * l * w + 2 * l * h + 2 * w * h; }
    float volume() { return Rectangle::area() * h; }
};
void fun(Point* p)
{
    cout << p->area() << "," << p->volume() << endl;
}
int main()
{
    //圆类
    Circle c1(-4.7, 5.8, 7.9);
    fun(&c1);
    //圆柱类
    Cylinder cy1(5.6, -7.4, 8.1, 23.5);
    fun(&cy1);
    //圆锥类
    Cone c2(2.5, 3.5, 4.5, 6.5);
    fun(&c2);
    //矩形类
    Rectangle r1(2.5, 3.5, 4.5, 5.5);
    fun(&r1);
    //长方体类
    Box r2(2.5, 3.5, 4.5, 5.5, 6.5);
    fun(&r2);
    return 0;
}