#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int* arr = new int[n];
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i]*(i%2==0?1:-1);
	}
	int a1=arr[0],a2 = 0;
	for(int i=0;i<n;i++){
		if(i%2==0 && arr[i]<a1) a1=arr[i];
		if(i%2==1 && arr[i]>a2) a2 = arr[i];
 	}
	if(a1<a2){sum+=2*a2;sum-=2*a1;}
	cout<<sum<<endl;
}
