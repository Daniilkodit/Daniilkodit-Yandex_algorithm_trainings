#include<iostream>
using namespace std;
int main()
{
	unsigned long long k,n;
	cin>>n>>k;
	switch(n%10)
	{
		case(2):
			n+=(k/4)*20;
			k %=4;
			if(k==1) n+=2;
			else if(k==2) n+=6;
			else if(k==3) n+=14;
			break;
		case(1):
			if(k==0) break;
			k -= 1;
			n+=1;
			n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break;
		case(3):
			if(k==0)break;
			if(k==1){n+=3;break;}
			k-=2;
			n+=9;
			n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break;
		case(4):
			if(k==0) break;
			if(k==1){n+=4;break;}
			if(k==2){n+=12;break;}
			k-=3;
			n+=18;
			n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break;
		case(5):
			if(k==0) break;
			n+=5;
			break;
		case(6):
			if(k==0) break;
			n+=6;
			k--;
			n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break;
		case(7):
			if(k==0) break;
			k--;
			n+=7;
			if(k==0) break;                                                                                                         if(k==1){n+=4;break;}                                                                                                   if(k==2){n+=12;break;}                                                                                                  k-=3;                                                                                                                   n+=18;                                                                                                                  n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break;
		case(8):
			if(k==0) break;
			if(k==1){n+=8;break;}
			k-=2;
			n+=14;
			n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                   break;
		case(9):
			if(k==0) break;
			k-=1;
			n+=9;
			if(k==0) break;                                                                                                         if(k==1){n+=8;break;}                                                                                                   k-=2;                                                                                                                   n+=14;
                        n+=(k/4)*20;                                                                                                            k %=4;                                                                                                                  if(k==1) n+=2;                                                                                                          else if(k==2) n+=6;                                                                                                     else if(k==3) n+=14;                                                                                                    break; 
	}
	cout<<n<<endl;
}
