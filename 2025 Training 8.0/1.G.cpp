#include<iostream>
#include<vector>
#include<string>
using namespace std;
int proverka(vector<string> pole,int n,int m, int i,int j,char s);
int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> pole(n);
	for(int i=0;i<n;i++)
	{
		cin>>pole[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char s =pole[i][j];
			if(s=='.') continue;
			if(proverka(pole,n,m,i,j,s)==1) {cout<<"Yes"; return 0;}
			
		}
	}
	cout<<"No";
}
int proverka(vector<string> pole,int n,int m, int i,int j,char s)
{
	int res=0;
	if(j+4<m)
	{
		res=1;
		for(int k=1;k<5;k++)
		{
			if(pole[i][j+k]!=s) {res=0;break;}
		}
		if(res==1) return res;
	}
	if(i+4<n)
	{
		res = 1;
		for(int k = 1;k<5;k++)
		{
			if(pole[i+k][j]!=s){res=0;break;}
		}
		if(res==1) return res;
	}
	if(i+4<n &&j+4<m)
	{
		res = 1;
                for(int k = 1;k<5;k++)
                {
                        if(pole[i+k][j+k]!=s){res=0;break;}
                }
                if(res==1) return res;
	}
	if(i+4<n &&j-4>=0)
        {
                res = 1;
                for(int k = 1;k<5;k++)
                {
                        if(pole[i+k][j-k]!=s){res=0;break;}
                }
                if(res==1) return res;
        }
	return 0;
}
