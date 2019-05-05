#ifndef ALIPAY_USERCONTROLLER_H
 #include <cstdio>
#include <iostream>
#include <cstring>
#include "userController.hpp"
using namespace std;

namespace Alipay {
int userController::getUserIndex(const char* username) const{
	
}

userController::userController(double i){
	interest_rate=i;
	usercount=0;
}
userController::~userController(){
	int i;
	for(i=usercount-1;i>=0;i--){
		delete users[i];
		users[i]=NULL;
	}
	usercount=0;
}
bool userController::createUser(const char* username, const char* password){
	if (usercount==MAX_USER)return 0;
	int len=strlen(username);
    if(len<6||len>20)
        return false;
    for(int i=0;i<len;i++){
        if((username[i]>='a'&&username[i]<='z')||(username[i]>='A'&&username[i]<='Z')||(username[i]>='0'&&username[i]<='9'));           
        else
            return false;
    }
    int len1=strlen(password);
    if(len1<8||len1>20)
        return false;
    for(int i=0;i<len1;i++){
        if(password[i]<48||(password[i]>57&&password[i]<65)||(password[i]>90&&password[i]<97)||password[i]>122)  
            return false;
    }
	users[usercount]=new user(username,password);
	if(users[usercount]==NULL)return 0;
	usercount++;
	return 1;
}
bool userController::deposite(const char* username, double amount){

	int i;
	for(i=0;i<usercount;i++){

		if (!strcmp(this->users[i]->getUsername(),username)){
			return users[i]->deposite(amount);
		}
	}
	return 0;
}
bool userController::withdraw(const char* username, double amount){

	int i;
	for(i=0;i<usercount;i++){

		if (!strcmp(this->users[i]->getUsername(),username)){
			return users[i]->withdraw(amount);
		}
	}
	return 0;
}
std::string userController::getUserInfoByName(const char* username) const{
	int i;
	for(i=0;i<usercount;i++){
		if (!strcmp(this->users[i]->getUsername(),username)){
			string bla;
   			char a[100];
   			sprintf(a,"%g",this->users[i]->getBalance());
  			bla.append(a);
 			string inf="username:";
 			inf.append(username);
 			inf+="\npassword:*********\nbalance:";
			return inf+bla;

		}
	}
	string ttt="No such user!";
	return ttt;
}
int userController::getUserCount(void) const{
	return usercount;
}
bool userController::removeUserByUsername(const char* username){
	if (usercount==0)return 0;
	user* ttt;
	int i=0;
	for(i=0;i<usercount;i++){

		if (!strcmp(this->users[i]->getUsername(),username)){
			delete users[i];
			users[i]=NULL;
			usercount--;
			for(;i<usercount;i++){
		ttt=users[i];
		users[i]=users[i+1];
		users[i+1]=ttt;
	}
	return 1;
		}
	}
	
	return 0;
	
}
bool userController::setInterest(double interest){
	interest_rate=interest;
	return 1;
}
void userController::payInterest(void){
	int i;
	for(i=0;i<usercount;i++){
		double t=users[i]->getBalance(); 
		users[i]->deposite(t*interest_rate);
	}
}
} 
#endif
