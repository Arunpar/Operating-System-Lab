#include<iostream>
using namespace std;
int num(int,int);
int numb(int,int);
main()
{
	int n1,n2,subs,sum;
	cout<<"Enter the First Number : ";
	cin>>n1;
	cout<<"Enter the Second Number : ";
	cin>>n2;
	subs=num(n1,n2);
	cout<<"----------------------------------\n";
	cout<<"The Substraction of Number is = "<<subs;
	sum=numb(n1,n2);
	cout<<"\nThe Sum of Number is = "<<sum;
}
int num(int x,int y)
{
	return(x-y);
}
int numb(int x,int y)
{
	return(x+y);
}
