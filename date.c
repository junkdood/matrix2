#ifndef DATE_H_
#define DATE_H_
#include<stdio.h>
#include<stdlib.h>

int daysOfMonth(int year,int month){ 
	switch(month){
		case 2:
			if(((year%4==0)&&(year%100!=0))||(year%400==0)){
				return 29;
			}
			else{
				return 28;
			}
		case 4:case 6:case 9:case 11:return 30;
	}
	return 31;
}

typedef struct {
  int year, month, day;
} Date;

Date* CreateDate(int year, int month, int day){
	Date* p;
	p=(Date*)malloc(sizeof(Date));
	p->year=year;
	p->month=month;
	p->day=day;
	return p;
} 
void DestroyDate(Date** p){
	free(*p);
	*p=0;
}
Date* CopyDate(const Date* date){
	Date* p;
	p=(Date*)malloc(sizeof(Date));
	p->year=date->year;
	p->month=date->month;
	p->day=date->day;
	return p;
}

int GetYear(const Date* date){
	return date->year;
}
int GetMonth(const Date* date){
	return date->month;
}
int GetDay(const Date* date){
	return date->day;
}
void SetYear(Date* date, int year){
	date->year=year;
}
void SetMonth(Date* date, int month){
	date->month=month;
}
void SetDay(Date* date, int day){
	date->day=day;
}
void SetDate(Date* date, int year, int month, int day){
	date->year=year;
	date->month=month;
	date->day=day;
}

char* GetDateString(const Date* date){
	char* p;
	int i=0,year,month,day;
	year=date->year;
	month=date->month;
	day=date->day;
	p=(char*)malloc(sizeof(char)*20);
	p[0]='0'+year/1000;
	p[1]='0'+(year%1000)/100;
	p[2]='0'+(year%100)/10;
	p[3]='0'+(year%10);
	p[4]='-';
	p[5]='0'+month/10;
	p[6]='0'+month%10;
	p[7]='-';
	p[8]='0'+day/10;
	p[9]='0'+day%10;
	p[10]='\0';
	return p;
}
void DestroyDateString(char** p){
	free(*p);
	*p=0;
}

void IncreaseDate(Date* date){
	date->day++;
	if(date->day>daysOfMonth(date->year,date->month)){
		date->day=1;
			date->month++;
		if(date->month>12){
			date->month=1;
			date->year++;
		}
	}
}
void DecreaseDate(Date* date){
	date->day--;
	if(date->day==0){
		date->month--;
		if(date->month==0){
			date->month=12;
			date->year--;
		}
		date->day=daysOfMonth(date->year,date->month);
	}
}


#endif
