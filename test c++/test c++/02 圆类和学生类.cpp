#include<iostream>
#include<string>
using namespace std;
const double PI = 3.14;
class Circle
{
//访问权限
public:
	//属性
	int m_r;
	//行为
	double perimeter()
	{
		//获取圆的周长
		return 2 * PI * m_r;
	}
};
class Student
{
public:
	//属性
	string m_name;
	int m_id;
	void showStudent()
	{
		cout << "姓名： " << m_name << " 学号： " << m_id<<endl;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setId(int id)
	{
		m_id = id;
	}
};
class People
{
public:
	//写名字
	void setname(string name)
	{
		m_name = name;
	}
	//读名字
	string getname()
	{
		return m_name;
	}
	//写年龄
	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "输入错误" << endl;
			m_age = 0;
			return;
		}
		m_age = age;
	}
	//读年龄
	int getage()
	{
		return m_age;
	}
	void setlover(string lover)
	{
		m_lover = lover;
	}

private:
	string m_name;//可读可写
	int m_age;//可读可写
	string m_lover;//可写
};
int main()
{
	Circle c1;//创建具体对象  c1
	c1.m_r = 10;//给对象的半径赋值
	cout << "圆的周长为： " << c1.perimeter() << endl;




	Student s1;
	s1.m_name = "张三";
	s1.m_id = 1;
	s1.showStudent();
	Student s2;
	s2.setName("李四");
	s2.setId(2);
	s2.showStudent();
	



	People p1;
	p1.setage(100);//设置年龄
	p1.setname("张三");//设置姓名
	p1.setlover("abc");
	cout << "姓名：" << p1.getname() << " 年龄" << p1.getage() << endl;
	system("pause");
	return 0;
}