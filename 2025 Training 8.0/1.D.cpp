#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	map<int,int> tems;
	for(int i =0;i<n;i++)
	{
		int a;
		cin>>a;
		tems[a]++;
	}
	for(auto& element : tems)
	{
		if(k>0) {cout<<element.first<<" ";k--;element.second--;}
		else return 0;

	}
	for(auto& elem: tems)
	{
		if(k>0 && k>=elem.second)
		{
			for(int i=0;i<elem.second;i++) cout<<elem.first<<" ";
			k-=elem.second;
		}
		else if(k>0 && k<elem.second)
		{
			for(int i=0;i<k;i++)cout<<elem.first<<" ";
			k = 0;
		}
		else return 0;
	}
}
