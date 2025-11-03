#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,t=1,b=0;
	cin>>n;
	vector<vector<long long>> arr(n,vector<long long>(2));
	for(int i=0;i<n;i++)
		cin>>arr[i][b]>>arr[i][t];
	int m;
	cin>>m;
	vector<vector<long long>> q(m,vector<long long>(3,-1));
	for(int i=0;i<m;i++) 
	{
		cin>>q[i][0];
		q[i][1] = i;
	}
	sort(q.begin(),q.end(),[](const vector<long long>&a,const vector<long long>&b){return a[0]<b[0];});
	int first=n-1,last;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i][b]<q[0][0] && arr[i+1][b]>=q[0][0])
		{
			first = i;
			break;
		}
	}
	last =first;
	q[0][2] = q[0][0]*arr[first][t];
	for(int i =1;i<m;i++)
	{
		for(int j=first;j<n-1;j++)
		{
			if(arr[j][b]<q[i][0] && arr[j+1][b]>=q[i][0])
			{
				first = j;
				q[i][2]  = q[i][0]*arr[first][t];
				break;
			}
		}
		if(q[i][2]==-1)
		{
			first = n-1;
			q[i][2]  = q[i][0]*arr[first][t];
		}
	}
	sort(q.begin(),q.end(),[](const vector<long long>&a,const vector<long long>&b){return a[1]<b[1];});
	for(int i=0;i<m;i++) cout<<q[i][2]<<endl;


}
