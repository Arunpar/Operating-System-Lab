#include<iostream>
using namespace std;
int main()
{
	int i,j,temp,f[10],fp[10];
	int N,P[15],Part[15],NP,PO[15],SP[15];

/*here N=Number of partition of memory
	Part[15]=Size of partition
	NP=Number of processes
	SP[15]=Store size of Processes
	PO[15]=Store Process Order
	N[15]=Store Partition Order
*/
	cout<<"Enter the Number of Partitions of Memory : ";
	cin>>N;
	cout<<endl;
	
	for(i=1;i<=N;i++)
	{
		P[i]=i;
		cout<<"Enter the Memory for Partition "<<i<<" : ";
		cin>>Part[i];
	}
	//Arrange partitions in descending order
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(Part[j]<Part[i])
			{
				temp=Part[i];
				Part[i]=Part[j];
				Part[j]=temp;
				
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
		}
	}
	printf("\nFree memory");
	for(i=1;i<=N;i++)
	cout<<"\nPartition : "<<P[i]<<" = "<<Part[i];

	cout<<"\n\nEnter the Number of Processes : ";
	cin>>NP;

 
	for(i=1;i<=NP;i++)
	{
		PO[i]=i;
		cout<<"Enter the Size for Process "<<i<<" : ";
		cin>>SP[i];
	}
	//Applying Worst-Fit Method
	cout<<"------------------------------------------------\n";
	cout<<"PROCESS \tPARTITION\tFREE_MEMORY";
	cout<<"\n------------------------------------------------\n";
	j=1;
	for(i=1;i<=N;i++)
	{
		f[i]=0;
		fp[j]=0;
	}
	while(j<=NP)
	{
		for(i=1;i<=N;i++)
		{
			if((Part[i]>=SP[j]) && (f[i]==0))
			{
				Part[i]=Part[i]-SP[j];
				fp[j]=1;     //process alloted
				f[i]=1;      //partition alloted
				cout<<" "<<PO[j]<<"\t\t"<<P[i]<<"\t\t"<<Part[i]<<endl;
				goto l1;
			}
		}
		l1:
		j++;
	}
	for(i=1;i<=N;i++)
	{
		if(f[i]==0)
		cout<<"\t\t"<<P[i]<<"\t\t"<<Part[i]<<endl;;
	}
	cout<<"The following Process is Not Allocatted Memory Block ";
	
	for(i=1;i<=NP;i++)
	{
		if(fp[i]==0)
		cout<<PO[i];
	}
}
