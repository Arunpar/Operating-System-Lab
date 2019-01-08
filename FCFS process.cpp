#include<iostream>
using namespace std;
int main()
{
	int N;
	cout<<"Enter the Processes : ";
	cin>>N;
	int AT[N],BT[N],CT[N],TAT[N],WT[N];
	
	for(int i=0;i<N;i++)
	{
		cout<<"\nEnter the ARRIVAL TIME of Process "<<i+1<<" : ";
		cin>>AT[i];
	}
	cout<<"---------------------------------------------";
	for(int i=0;i<N;i++)
	{
		cout<<"\nEnter the BURST TIME of Process "<<i+1<<" : ";
		cin>>BT[i];
	}
	CT[0]=BT[0]+AT[0];
	int temp=CT[0];
	
	for(int i=1;i<N;i++)
	{
		if(CT[i-1]>AT[i])
		{
		CT[i]=temp+BT[i];
		temp=CT[i];
	}
	else
	{
		CT[i]=AT[i]+BT[i];
			temp=CT[i];
	}
	}
	float AVG_TAT=0,AVG_WT=0,AVG_CT=0;
	
	cout<<"---------------------------------------------";
	for(int i=0;i<N;i++)
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
		
		AVG_CT=AVG_CT+CT[i];
		cout<<"\nCOMPLITION TIME of Process "<<i+1<<" : "<<CT[i];
	}
	cout<<"\nAverage COMPLITION TIME of Process "<<AVG_CT/N;
	
	cout<<"\n---------------------------------------------";
	for(int i=0;i<N;i++)
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
		
		AVG_TAT=AVG_TAT+TAT[i];
		cout<<"\nTURN AROUND TIME of Process "<<i+1<<" : "<<TAT[i];
	}
	cout<<"\nAverage TURN AROUND TIME of Process "<<AVG_TAT/N;
	
	cout<<"\n---------------------------------------------";
	for(int i=0;i<N;i++)
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
		
		AVG_WT=AVG_WT+WT[i];
		cout<<"\nWAITING TIME of Process "<<i+1<<" : "<<WT[i];
	}
	cout<<"\nAverage WAITING TIME of Process "<<AVG_WT/N;
}
