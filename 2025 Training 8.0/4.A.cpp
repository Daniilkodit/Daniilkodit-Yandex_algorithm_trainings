#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	vector<int>count(2);
	vector<int>count_now(2);
	vector<vector<int>> arr;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int time_come,time_left;
		time_come = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
		time_left = stoi(s.substr(6,2))*60 + stoi(s.substr(9,2));
		arr.push_back({time_come,1,0});
		arr.push_back({time_left,-1,1});
	}
	cin>>m;
	for(int i=0;i<m;i++)
        {
                string s;
                cin>>s;
                int time_come,time_left;
                time_come = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
                time_left = stoi(s.substr(6,2))*60 + stoi(s.substr(9,2));
                arr.push_back({time_come,1,1});
                arr.push_back({time_left,-1,0});
        }
	sort(arr.begin(),arr.end(),[](const vector<int>&a,const vector<int>&b){
			if(a[0]==b[0])
				return a[1]<b[1];
			return a[0]<b[0];
			});

	for(int i=0;i<2*n+2*m;i++)
	{
		int c =arr[i][1],office = arr[i][2];
		if(c==1 && count_now[office]==0)
			count[office]++;
		else if(c==-1)
			count_now[office]++;
		else if(c==1)
			count_now[office]--;
	}
	cout<<count[0]+count[1]<<endl;
}
