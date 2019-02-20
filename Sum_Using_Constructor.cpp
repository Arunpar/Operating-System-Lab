#include<iostream>
using namespace std;
class ABC
{
	int a,b,c;
	public:
		ABC(int n,int m)
		{
			a=n;
			b=m;
		}
		void add();
		void sub();
		};
		void ABC::add()
		{
			c=a+b;
			cout<<"---------------------------------\n";
			cout<<"The Sum of Numbers is = "<<c;
		}
		void ABC::sub()
		{
			c=a-b;
			cout<<"\nThe Subtraction of Numbers is = "<<c;
		}
 main()
{
	int n1,n2;
	cout<<"Enter the First Number : ";
	cin>>n1;
	cout<<"Enter the Second Number : ";
	cin>>n2;
	ABC a (n1,n2);
	a.add();
	a.sub();
}
