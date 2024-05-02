#include<iostream>
using namespace std;
int main()
{
	int a[5] = {10,20,30,40,50};
	int i, item, flag;
	
	cout<<"enter the number to search - ";
	cin>>item;
	for(i=0;i<5;i++)
	{
		if(a[i]==item)
		{
			flag=i+1;
			break;
		}
		else{
			flag = 0;
		}
	}
	if(flag!=0)
		cout<<"item found";
	else
		cout<<"item not found";
	return 0;
}
