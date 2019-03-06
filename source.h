#ifndef SOURCE_H_
#define SOURCE_H_
#include <string>
#include <cstdio>

class Date
{
    public:
        Date(int newYear,int newMonth,int newDay);
        int getYear();
        void setYear(int newYear);
        int getMonth();
        int getDay();
        void setMonth(int Month);
        void setDay(int Day);

  private:
        int year;
        int month;
        int day;
};

Date::Date(int newYear,int newMonth,int newDay){
	year=newYear;
	month=newMonth;
	day=newDay;

}

int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}

void Date::setYear(int newYear){
	year=newYear;
	return;
}
void Date::setMonth(int Month){
	month=Month;
	return;
}
void Date::setDay(int Day){
	day=Day;
	return;
}

class Person
{
public:
  Person(int id, int year, int month, int day);
  Person(const Person &); // copy constructor
  ~Person();
  int getId()const;
  Date * getBirthDate()const;
  static int getNumberOfObjects(){
  	return numberOfObjects;
  }

private:
  int id;
  Date *birthDate; 
  static int numberOfObjects;
};

int Person::numberOfObjects=0;

Person::Person(int Id, int year, int month, int day){
	numberOfObjects++;
	birthDate = new Date(year,month,day);
	id=Id;
}
Person::Person(const Person &p){
	id=p.getId();
	birthDate = new Date(p.getBirthDate()->getYear(),p.getBirthDate()->getMonth(),p.getBirthDate()->getDay());
    numberOfObjects++;
}
Person::~Person(){
	numberOfObjects--;
	delete birthDate;
}

int Person::getId()const{
	return id;
}
Date * Person::getBirthDate()const{
	return birthDate;
}

#endif
