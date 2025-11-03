#include<iostream>
#include<string>
#define Min(a,b) a<b? a:b
using namespace std;
int main()
{
	string s;
	cin>>s;
	int*dpL = new int[s.size()+1];
	int*dpR = new int[s.size()+1];
	dpL[0] = 0;
	dpR[0] = 10;
	dpL[1] = s[0]=='R' ? 0:1;
	dpR[1] = s[0]=='B' ? 2:1;
	for(int i=2;i<=s.size();i++)
	{
		dpL[i] = Min(dpL[i-1] + (s[i-1]=='R' ? 0:1),dpR[i-1]+(s[i-1]=='L' ? 1:2));
		dpR[i] = Min(dpR[i-1] + (s[i-1]=='L' ? 0:1),dpL[i-1] +(s[i-1]=='B' ? 2:1));
	}
	cout<<(dpL[s.size()]<dpR[s.size()] ? dpL[s.size()]+1:dpR[s.size()])<<endl;
}
