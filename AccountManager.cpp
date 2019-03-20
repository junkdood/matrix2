#include "AccountManager.hpp"


#include "Account.hpp"
#include <string>
using std::string;

AccountManager::AccountManager (){
	accountNumber=0;
}

void AccountManager::open(string s){
	Account a(s,0);
	accountlist[accountNumber]=a;
	accountNumber++;
	
}

void AccountManager::close(string s){
	Account a,temp;
	for(int i=0;i<accountNumber;i++){
		if(s==accountlist[i].getName()){
			accountlist[i]=a;
			for(int r=i;r<accountNumber-1;r++){
				temp=accountlist[r];
				accountlist[r]=accountlist[r+1];
				accountlist[r+1]=temp;
			}
			break;
		}
	}
	accountNumber--;
}

void AccountManager::depositByName(string s,double p){
	for(int i=0;i<accountNumber;i++){
		if(s==accountlist[i].getName()){
			accountlist[i].deposit(p);
			break;
		}
	}
}

bool AccountManager::withdrawByName(string s,double p){
	for(int i=0;i<accountNumber;i++){
		if(s==accountlist[i].getName()){
			if(accountlist[i].withdraw(p)){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}

double AccountManager::getBalanceByName(string s){
	for(int i=0;i<accountNumber;i++){
		if(s==accountlist[i].getName()){
			return accountlist[i].getBalance();
		}
	}
}

Account AccountManager::getAccountByName(string s){
	for(int i=0;i<accountNumber;i++){
		if(s==accountlist[i].getName()){
			return accountlist[i];
		}
	}
}
