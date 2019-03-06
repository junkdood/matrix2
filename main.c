#include <iostream>
#include<cstring> 
#include<cmath>
using namespace std;

int main(){
	int m,s,T,t;
	int ma,x;
	while(cin>>m>>s>>T){
		int flag=0;
		t=0;
		x=0;
		if(T==0){
			cout<<"No"<<endl<<x<<endl;
			flag=1;
		}
		for(ma=m;ma>=10;ma-=10){
			x+=60;
			t++;
			if(x>=s&&t<=T){
				cout<<"Yes"<<endl<<t<<endl;
				flag=1;
				break;
			}
			else if(t>=T){
				cout<<"No"<<endl<<x<<endl;
				flag=1;
				break;
			}
		}
		while(t<T&&x<s){
			if(ma>=10){
				t++;
				x+=60;
				ma-=10;
			}
			else if(ma<=9&&ma>=6){
				if(s-x<=17){
					t++;
					cout<<"Yes"<<endl<<t<<endl;
					flag=1;
					break;
				}
				else{
					t++;
					if(t==T){
						x+=17;
					}
					ma+=4;
				}
			}
			else if(ma<=5&&ma>=2){
				if(s-x<=17){
					t++;
					cout<<"Yes"<<endl<<t<<endl;
					flag=1;
					break;
				}
				else if(s-x<=34){
					t++;
					x+=17;
				}
				else{
					t++;
					if(t==T){
						x+=17;
					}
					ma+=4;
				}
			}
			else{
				if(s-x<=17){
					t++;
					cout<<"Yes"<<endl<<t<<endl;
					flag=1;
					break;
				}
				else if(s-x<=34){
					t++;
					x+=17;
				}
				else if(s-x<=51){
					t++;
					x+=17;
				}
				else{
					t++;
					if(t==T){
						x+=17;
					}
					ma+=4;
				}
			}
		}
		if(flag==0){
			if(x>=s&&t<=T){
				cout<<"Yes"<<endl<<t<<endl;
			}
			else {
				cout<<"No"<<endl<<x<<endl;
			}
		}
		
	}
	return 0;
}
