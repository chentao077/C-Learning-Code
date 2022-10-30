#include<iostream>
using namespace std;


//����
class Fraction
{
private:
	int mun;//��ĸ
	int son;//����
public:
	Fraction()
	{}
	Fraction(int a, int b)
	{
		son = a;
		mun = b;
	}
	//��Ա����ʵ��
	//�����ӷ�
	Fraction operator+(Fraction &c1)
	{
		Fraction c2;
		c2.mun = this->mun + c1.mun;
		c2.son = this->son * c2.mun + this->mun * c2.son;
		return c2;
	}

	//��������
	Fraction operator-(Fraction& c1)
	{
		Fraction c2;
		c2.mun = this->mun * c1.mun;
		c2.son = this->son * c1.mun - this->mun * c1.son;
	}

	//�����˷�
	Fraction operator*(Fraction& c1)
	{
		Fraction c2;
		c2.mun = this->mun * c1.mun;
		c2.son = this->son * c1.son;
		return c2;
	}

	//��������
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
//��Ԫ����ʵ��
//�����ӷ�
Fraction operator+(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.mun + c1.mun * c2.son;
	return c3;
}

//��������
Fraction operator-(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.mun - c1.mun * c2.son;
	return c3;
}

//�����˷�
Fraction operator*(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.mun;
	c3.son = c1.son * c2.son;
	return c3;
}

//��������
Fraction operator/(Fraction &c1, Fraction &c2)
{
	Fraction c3;
	c3.mun = c1.mun * c2.son;
	c3.son = c1.son * c2.mun;
	return c3;
}

//����
class Complex
{
private:
	double real; //ʵ��
	double image;//�鲿
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