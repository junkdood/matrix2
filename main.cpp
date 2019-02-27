#include <iostream>
#include<cstring> 
#include<cmath>
using namespace std;

int z;

void pre(int* a,int n){
	if(n>=z)return;
	cout<<*(a+n)<<endl;
	pre(a,n*2+1);
	pre(a,n*2+2);
}

void ino(int* a,int n){
	if(n>=z)return;
	ino(a,n*2+1);
	cout<<*(a+n)<<endl;
	ino(a,n*2+2);
}

void pos(int* a,int n){
	if(n>=z)return;
	pos(a,n*2+1);
	pos(a,n*2+2);
	cout<<*(a+n)<<endl;
}

int main(){
	int i;
	cin>>z;
	int a[z];
	for(i=0;i<z;i++){
		cin>>a[i];
	}
	cout<<"Preorder"<<endl;
	pre(a,0);
	
	cout<<"Inorder"<<endl;
	ino(a,0);
	
	cout<<"Postorder"<<endl;
	pos(a,0);
	
	return 0;
}
