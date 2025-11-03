#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int count = 1;
	map<char,int> alf;
	for(int i=0;i<s.size();i++)
	{
		alf[s[i]]++;
	}
	for(int i=0;i<s.size();i++)
	{
		for(auto& element:alf)
		{
			if(element.first!=s[i]) count+=element.second;
			else element.second--;
		}
	}
	cout<<count<<endl;
}
