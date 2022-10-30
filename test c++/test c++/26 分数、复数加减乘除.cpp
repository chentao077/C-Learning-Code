#include<iostream>
using namespace std;


//分数
class Fraction
{
private:
	int mun;//分母
	int son;//分子
public:
	Fraction()
	{}
	Fraction(int a, int b)
	{
		son = a;
		mun = b;
	}
	//成员函数实现
	//分数加法
	Fraction operator+(Fraction &c1)
	{
		Fraction c2;
		c2.mun = this->mun + c1.mun;
		c2.son = this->son * c2.mun + this->mun * c2.son;
		return c2;
	}

	//分数减法
	Fraction operator-(Fraction& c1)
	{
		Fraction c2;
		c2.mun = this->mun * c1.mun;
		c2.son = this->son * c1.mun - this->mun * c1.son;
	}

	//分数乘法
	Fraction operator*(Fraction& c1)
	{
		Fraction c2;
		c2.mun = this->mun * c1.mun;
		c2.son = this->son * c1.son;
		return c2;
	}

	//分数除法
	Fraction operator/(Fraction& c1)
	{
		Fraction c2;
		c2.mun = this->mun * c2.son;
		c2.son = this->son * c2.mun;
		return c2;
	}
	friend  Fraction operator+(Fraction &c1, Fraction &c2);
	friend  Fraction operator-(Fraction &c1, Fraction &c2);
	friend  Fraction operator*(Fraction &c1, Fraction &c2);
	friend  Fraction operator/(Fraction &c1, Fraction &c2);

};
//友元函数实现
//分数加法
Fraction operator+(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.mun + c1.mun * c2.son;
	return c3;
}

//分数减法
Fraction operator-(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.mun - c1.mun * c2.son;
	return c3;
}

//分数乘法
Fraction operator*(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.son;
	return c3;
}

//分数除法
Fraction operator/(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.son;
	c3.son = c1.son * c2.mun;
	return c3;
}

//复数
class Complex
{
private:
	double real; //实部
	double image;//虚部
public:
	Complex(double r = 0, double i = 0)
	{
		real = r;
		image = i;
	}
	Complex operator+( Complex& c2)
	{
		Complex c3;
		c3.image = image + c2.image;
		c3.real = real + c2.real;
		return c3;
	}
	Complex operator-(Complex& c2)
	{
		Complex c3;
		c3.image = image - c2.image;
		c3.real = real - c2.real;
		return c3;
	}
	Complex operator*(Complex& c2)
	{
		Complex c3;
		c3.image = real * c2.image + image * c2.real;
		c3.real = real * c2.real - image * c2.image;
		return c3;
	}
	Complex operator/(Complex& c2)
	{
		Complex c3;
		float tmp = c2.real * c2.real - c2.image * c2.image;
		c3.image = (image * c2.real - real * c2.image) / tmp;
		c3.real = (real * c2.real + image * c2.image) / tmp;
		return c3;
	}
	friend Complex operator+(Complex& c1, Complex& c2);
	friend Complex operator-(Complex& c1, Complex& c2);
	friend Complex operator*(Complex& c1, Complex& c2);
	friend Complex operator/(Complex& c1, Complex& c2);
};
Complex operator+(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.image = c1.image + c2.image;
	c3.real = c1.real + c2.real;
	return c3;
}
Complex operator-(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.image = c1.image - c2.image;
	c3.real = c1.real - c2.real;
	return c3;
}
Complex operator*(Complex& c1, Complex& c2)
{
	Complex c3;
	c3.image = c1.real * c2.image + c1.image * c2.real;
	c3.real = c1.real * c2.real - c1.image * c2.image;
	return c3;
}
Complex operator/(Complex& c1, Complex& c2)
{
	Complex c3;
	float tmp = c2.real * c2.real - c2.image * c2.image;
	c3.image = (c1.image * c2.real - c1.real * c2.image) / tmp;
	c3.real = (c1.real * c2.real + c1.image * c2.image) / tmp;
	return c3;
}
int main()
{
	return 0;
}