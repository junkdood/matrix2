

#include <iostream>
#include <cstring>
#include "user.hpp"
using namespace std;
namespace Alipay {
user::user(const char* u, const char* p){
	strcpy(username,u);
	strcpy(password,p);
	balance=0;
}

user::~user(){
	
}

const char* user::getUsername() const{
	return username;
}

const char* user::getPassword() const{
	return password;
}

const void user::setUsername(const char* u){
	strcpy(username,u);
}

const void user::setPassword(const char* p){
	strcpy(password,p);
}

double user::getBalance(){
	return balance;
}

bool user::withdraw(double amount){
	if (amount>balance||amount<0)return 0;
	else {
		balance-=amount;
		return 1;
	}
}

bool user::deposite(double amount){
	if(amount<0)return 0;
	balance+=amount;
	return 1;
}
} 
