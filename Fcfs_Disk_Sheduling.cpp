#include<iostream>
using namespace std;
int main()
{
	int N;
	cout<<"Enter Number of Locations : ";
	cin>>N;
	int loc[N],pos,mov,total=0;
	/*
	here N=No. of Locations 
	loc[N]=Paticular Locations
	pos=initial postion of head
	mov=movement of disk in one location
	total=total movements of disk after covered all locations
	*/
	
	cout<<endl;
	for(int i=1;i<=N;i++)
	{
		cout<<"Enter Location "<<i<<" : ";
		cin>>loc[i];
	}
	cout<<"-----------------------------------\n";
	cout<<"Enter Postion of Head Initially : ";
	cin>>pos;
	
	for(int i=1;i<=N;i++)
	{
		if(loc[i]>pos)
		{
			mov=loc[i]-pos;	
			pos=loc[i];
			total=total+mov;
		}
		
		else
		{
			mov=pos-loc[i];
			pos=loc[i];
			total=total+mov;
		}
	}
	cout<<"Total Movement of Disk : ";
	cout<<total;
	return 0;
}
