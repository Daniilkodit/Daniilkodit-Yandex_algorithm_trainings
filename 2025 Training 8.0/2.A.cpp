#include<iostream>
using namespace std;
int main(void)
{
	int n,i;
	cin>>n;
	long long* arr = new long long[n + 1]{};
	if(n==1) {cout<<"1"<<endl; return 0;}
	arr[n] =1;
	arr[n-1] = 1;
	arr[n-2] = 2;
	for(i =n-3;i>=0;i--)
	{
		arr[i] += arr[i+1] +arr[i+2] + arr[i+3];
	}
	cout<<arr[0]<<endl;

}
