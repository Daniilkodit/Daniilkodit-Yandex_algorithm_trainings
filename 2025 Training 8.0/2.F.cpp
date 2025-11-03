#include<iostream>
using namespace std;
#define Max(a,b) a<b ? b:a
int main()
{
	int n;
	cin>>n;
	char* field = new char[n*3];
	int* dp = new int[n*3]{};
	for(int i=0;i<n;i++) cin>>field[i*3]>>field[i*3+1]>>field[i*3+2];
	for(int i=0;i<3;i++)
	{
		if(field[i]=='W') dp[i] = -1;
		else if(field[i]=='.')dp[i] =0;
		else dp[i] = 1;
	}
	for(int j=1;j<n;j++)
	{
		dp[j*3] = Max(dp[(j-1)*3],dp[(j-1)*3 + 1]);
		dp[j*3+2] = Max(dp[(j-1)*3+2],dp[(j-1)*3 + 1]);
		dp[j*3+1] = Max(dp[(j-1)*3],(Max(dp[(j-1)*3+2],dp[(j-1)*3 + 1])));
		for(int i=0;i<3;i++)
        	{
			if(dp[i+j*3]==-1) continue;
			if(field[i+j*3]=='W') dp[i+j*3] = -1;
			else if(field[i+j*3]=='.')dp[i+j*3] +=0;
			else dp[i +j*3] += 1;
        	}
	}
	int dpmax =0;
	for(int j=0;j<n;j++)
	{
		if(dp[j*3]==-1 && dp[j*3+1]==-1 && dp[j*3+2]==-1) break;
		dpmax = Max((Max(dp[j*3],dpmax)),(Max(dp[j*3+2],dp[j*3 + 1])));
	}
      
	cout<<dpmax<<endl;
}
