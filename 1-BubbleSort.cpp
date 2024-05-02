#include<iostream>
using namespace std;
int main()
{
	int i, j, temp;
	int a[5] = {2,5,1,10,9};
	for(i=0; i<5; i++)
	{
		cout<<a[i]<<" ";
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if( a[j] < a[i])  
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout<<endl;
	cout<<"Descending Ordered list - ";
	for(i=0; i<5; i++) 
	{
		cout<<a[i]<<" ";
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if( a[j] > a[i])   
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout<<endl;
	cout<<"Ascending Ordered list - ";
	for(i=0; i<5; i++) 
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
