#include<iostream>
#include<vector>
using namespace  std;
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> dp(151, vector<int>(n+1,0));
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<j;k++)
			{
				dp[j][i] += dp[k][i-j];
			}	
		}
		dp[i][i] = 1;
	}
	int sum=0;
	for(int k=1;k<151;k++) sum+=dp[k][n];
	cout<<sum<<endl;
}
