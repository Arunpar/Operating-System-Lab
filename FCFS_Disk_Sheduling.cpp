#include<iostream>
using namespace std;
int main()
{
	int i,j,sum=0,N;
 	int ar[20],tm[20];
 	int disk;
 	
 	cout<<"Enter Number of Locations : ";
 	cin>>N;
 	cout<<"Enter Position of Element : ";
 	cin>>disk;
 	
 	cout<<"Enter Elements of Disk Queue : \n";
 	for(i=0;i<N;i++)
 	{
 		cin>>ar[i];
 		tm[i]=disk-ar[i];
 		
 		if(tm[i]<0)
 		tm[i]=ar[i]-disk;

 		disk=ar[i];
 		sum=sum+tm[i];
 	}
	cout<<"\nMovement of Total Cylinders : ";
	cout<<sum;
	return 0;
}
