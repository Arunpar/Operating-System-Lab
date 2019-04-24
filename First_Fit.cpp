#include<iostream>
using namespace std;
int main()
{
	int n,m,c=0;
	cout<<"Enter the Number of Processes : ";
	cin>>n;
	
	int s[n],p[m];
	
	/*
	here n= No. of Processes
	s[n]=Size of Processes
	m=No.of Partition of memory
	p[m]=Size of Partition
	*/
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter the size of Process "<<i<<" : ";
		cin>>s[i];
	}
	
	cout<<"\nEnter the Number of Partitions of Memory : ";
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		cout<<"Enter the size of Partition "<<i<<" : ";
		cin>>p[i];
	}
	
	cout<<"-------------------------------------------\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i]<=p[j])
			{
				cout<<"Process "<<i<<" has Allocate a Memory Block "<<j;
				cout<<endl;
				p[j]=0;
				c++;
				break;
			}
		}
		if(c==0)
		cout<<"Process "<<i<<" has not Allocated any Memory Block\n";
		c=0;
	}
	
	return 0;
}
