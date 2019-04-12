#include<bits/stdc++.h>
using namespace std;
main()
{
	int N,B;
	cout<<"Enter the Number of Processes        : ";
	cin>>N;

	cout<<"Enter the Number of blocks in Memory : ";
	cin>>B;
	
	int A[N],MEM[B],S[B]={0},SA[N]={0},CHOICE[B]={0};
	/*
	here A[N]=Size of Processes
	and MEM[B]=Memory Size Used by particular used block or hole
	and S[B]=Sum upto Starting address
	and SA[N]=Starting Address of processes
	and CHOICE[B]=Used Memory or Hole 
	*/
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<"Enter Size of Process "<<i+1<<" : ";
		cin>>A[i];
	}


	for(int i=0;i<B;i++)
	{
		cout<<"\nEnter '1' for Used And '2' for Hole : ";
		cin>>CHOICE[i];
		
		if(CHOICE[i]==1)
		{
			cout<<"Enter the Size of Used Memory       : ";
			cin>>MEM[i];
		}
		else
		{
			cout<<"Enter the Size of Hole              : ";
			cin>>MEM[i];
		}
	}
	
	int flag[B]; 
	for(int i=0;i<B;i++) 
	flag[i]=0;
	
	for(int i=0;i<N;i++)
	{  
		for(int j=0;j<B;j++)
		{   
			S[i]+=MEM[j];
			
			if(MEM[j]>=A[i] && flag[j]==0 && CHOICE[j]==2)
			{
				SA[i]=S[i]-MEM[j];
				MEM[j-1]=MEM[j-1]+A[i];
				MEM[j]=MEM[j]-A[i];
				
				if(MEM[j]>0)
				flag[j]=0;
				 
				else flag[j]=1; 
				break;
			}
	
		}
	}
	cout<<"\n-------------------------------------\n";
	for(int i=0;i<N;i++) 
	cout<<"Starting Address For Process "<<i+1<<" : "<<SA[i]<<"  \n";
}
