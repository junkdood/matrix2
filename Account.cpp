#include "Account.hpp"

#include <iostream>
using namespace std;

using std::string;

Account::Account(){
	balance=0;
}

Account::Account(string s, double p){
	name=s;
	balance=p;
}

void Account::deposit(double p){
	balance+=p;
}

bool Account::withdraw(double p){
	if(p>balance){
		return 0;
	}
	else{
		balance-=p;
		return 1;
	}
}

string Account::getName(){
	return name;
}

double Account::getBalance(){
	return balance;
}
