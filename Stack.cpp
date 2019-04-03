#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "Stack.hpp"

class Stack {
  struct node {
    int num;
    node* next;
    node() { num = 0; next = NULL; }
    node(int n, node* p = NULL) { num = n; next = p; }
  };

  struct {
    node* data;
    int* count;
  } p;

  void copyOnWrite();
public:
  Stack();                        // ??????
  Stack(const Stack&);            // ??????
  ~Stack();                       // ??????

  Stack operator=(const Stack&);  // ??????
  void push(int);                 // ??
  void pop();                     // ??
  int top() const;                // ??????
  bool empty() const;             // ???????
  void clear();                   // ???
};

Stack::Stack(){
	p.data=NULL;
	p.count=new int;
	*p.count=1;
}

Stack::Stack(const Stack& pp){
	this->p.data=NULL;
	this->p.count=NULL;
	this->p.data=pp.p.data;
	this->p.count=pp.p.count;
	*p.count+=1;
}

Stack::~Stack(){
	clear();
}

Stack Stack::operator=(const Stack& pp){
	if(this==&pp)return *this;
	this->clear();
	this->p.data=pp.p.data;
	this->p.count=pp.p.count;
	*p.count+=1;
	return *this;
}

void Stack::push(int a){
	if(*p.count==1){
		node* temp=new node(a,p.data);
		p.data=temp;
		temp=NULL;
	}
	else{
		*p.count-=1;
		copyOnWrite();
		p.count=new int;
		*p.count=1;
		node* temp=new node(a,p.data);
		p.data=temp;
		temp=NULL;
	}
}

void Stack::pop(){
	if(*p.count==1){
		node* temp=p.data;
		p.data=p.data->next;
		delete temp;
		temp=NULL;
	}
	else{
		*p.count-=1;
		copyOnWrite();
		p.count=new int;
		*p.count=1;
		node* temp=p.data;
		p.data=p.data->next;
		delete temp;
		temp=NULL;
	}
	
}

int Stack::top() const{
	if(p.data==NULL)return 0;
	return p.data->num;
}

bool Stack::empty() const{
	if(p.data==NULL)return 1;
	return 0;
}

void Stack::clear(){
	if(p.count==NULL)return;
	else if(*p.count==1){
		node* temp=p.data;
		while(temp!=NULL){
			p.data=p.data->next;
			delete temp;
			temp=p.data;
		}
		delete p.count;
		p.count=NULL;
	}
	
	else{
		p.data=NULL;
		*p.count-=1;
		p.count=NULL;
	}
	
}

void Stack::copyOnWrite(){
	if(p.data==NULL){
		return;
	}
	else{
		node* temp=new node;
		node* f=p.data;
		node* ff=temp;
		while(f!=NULL){
			ff->num=f->num;
			f=f->next;
			if(f==NULL){
				break;
			}
			ff=ff->next;
			ff=new node;
			
		}
		this->p.data=temp;
		
	}
}
#endif
