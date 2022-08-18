#include<iostream>
using namespace std;
//����������ģ��
template<class T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//�������������
template <class T>
void mysort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			myswap(arr[min], arr[i]);
		}
	}
}

//��ӡ����
template<class T>
void myprint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	//����char����
	char arr[] = "bdcfeagh";
	int len = sizeof(arr) / sizeof(arr[0]);
	mysort(arr, len);
	myprint(arr, len);
}

void test2()
{
	//����int����
	int arr[] = { 7,5,8,1,3,9,2,4,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	mysort(arr, len);
	myprint(arr, len);
}

int main()
{
	test1();
	test2();
	return 0;
}