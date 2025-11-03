#include<iostream>
using namespace std;
int main()
{
	long long int a,b,s;
	long long int left,right,m;
	cin>>a>>b>>s;
	left = max(a,b);
	right = s+a+b;
	while(left<=right)
	{
		m = (left+right)/2;
		if((m-a)*(m-b)>s)
			right = m-1;

		else if((m-a)*(m-b)<s)
			left = m+1;
		else
		{
			cout<<m<<endl;
		       	return 0;
		}
						
	}
	cout<<-1<<endl;
}
