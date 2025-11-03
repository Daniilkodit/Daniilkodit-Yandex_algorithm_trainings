#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long> prefix_sum(n+1);
	for(int i = 1;i<n+1;i++)
	{
		long long a;
		cin>>a;
		prefix_sum[i]  = prefix_sum[i-1] + a;
	}
	int l = 1,r = n,lmin = 1,rmin =n;
	long long sum = 0;
	long long sum_min = prefix_sum[n];
	while(l<r)
	{
		sum = prefix_sum[n]-prefix_sum[r-1];
		if(labs(prefix_sum[l]-sum)<sum_min)
		{
			lmin = l;
			rmin = r;
			sum_min = labs(prefix_sum[l]-sum);
		}
		if(prefix_sum[l]>sum) r--;
		else if(prefix_sum[l]<sum) l++;
		else break;
	}
	cout<<sum_min<<" "<<lmin<<" "<<rmin<<endl;


}
