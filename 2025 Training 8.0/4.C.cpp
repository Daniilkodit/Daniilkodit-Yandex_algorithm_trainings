#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main()
{
	int n,m;
	long x,c=0,a,kk = 0;
	cin>>n>>x;
	vector<long> prefix_sum(n);
	deque<long> candidates;
	cin>>a;
	prefix_sum[0] = (a>=x ? 1:0);  
	candidates.push_back(a);
	for(int i=1;i<n;i++)
	{
		cin>>a;
		prefix_sum[i] = prefix_sum[i-1]  + (a >= x ? 1 : 0);
		candidates.push_back(a);
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			cin>>a;
			prefix_sum.push_back(prefix_sum.back()+(a >= x ? 1 : 0));
			candidates.push_back(a);
		}
		else if(k==2)
		{
			c += (candidates.front()>=x ? 1:0);
			candidates.pop_front();
			kk++;
		}
		else
		{
			cin>>a;
			a+=kk-1;
			if(a<0)
				cout<<0<<endl;
			else
				cout<<prefix_sum[a]-c<<endl;
		}
	}


}
