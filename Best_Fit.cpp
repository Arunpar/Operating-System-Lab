#include<iostream>
using namespace std;
#define max 10
class BestFit
{
	public:
		int N,A[max],M[5]={100,500,300,600,200},I[5]={1,2,3,4,5},temp;
		void getdata()
		{
			cout<<"Enter Number of Processes : ";
			cin>>N;
			cout<<endl;

			for(int i=0;i<N;i++)
			{
				cout<<"Enter the Size of Process "<<i+1<<" : ";
				cin>>A[i];
			}
		}
		void calculation()
		{
			for(int i=0;i<=3;i++)
			{
				for(int j=0;j<=3-i;j++)
				{
					if(M[j]>M[j+1])
					{
						temp=M[j];
						M[j]=M[j+1];
						M[j+1]=temp;
					
						temp=I[j];
						I[j]=I[j+1];
						I[j+1]=temp;
					}
				}
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<5;j++)
				{	
					if((A[i]<=M[j]) && (I[j]!=-1))
					{
						cout<<"Slot of Memory Used by Process "<<i+1<<":"<<I[j]<<endl;
						I[j]=-1;
						break;	
					}
					if((j==4) && (A[i]>M[j]))	
					cout<<"No Memory is Allocated to Process "<<i+1<<endl;	
				}	
			}
		}
};
int main()
{
	BestFit obj;
	obj.getdata();
	cout<<"\nMemory Slots Available : "<<endl;
	for(int i=0;i<5;i++)
	cout<<obj.M[i]<<"	";
	
	cout<<"\n\n----------------------------------------\n";
	obj.calculation();
}
