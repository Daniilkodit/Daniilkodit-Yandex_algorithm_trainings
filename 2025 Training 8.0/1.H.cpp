#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int bit_len = n/m;
	map<string,vector<int>> bit;
	for(int i = 0;i<m;i++)
	{
		string q;
		cin>>q;
		bit[q].push_back(i+1);
	}
	int*solve = new int[m];
	for(int i=0;i<m;i++)
	{
		string q = s.substr(i*bit_len,bit_len);
		solve[i] = bit[q].back();
		bit[q].pop_back();
	}
	for(int i=0;i<m;i++) cout<<solve[i]<<" ";
	
}
