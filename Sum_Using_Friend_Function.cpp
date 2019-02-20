#include<iostream>
using namespace std;
class B;
class A 
{
	int a;
	public:
		void Setdata()
		{
			cout<<"Enter the First Number : ";
			cin>>a;
		}
		friend void fun(A , B);
};
class B
{
	int b;
	public:
		void Setdata()
		{
			cout<<"Enter the Second Number : ";
			cin>>b;
		}
		friend void fun(A , B);
};
void fun(A o1 , B o2)
{
	cout<<"The Sum of Numbers are : ";
	cout<<o1.a+o2.b;
}
main()
{
	A obj1;
	B obj2;
	obj1.Setdata();
	obj2.Setdata();
	fun(obj1 , obj2);
}
