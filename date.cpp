#ifndef DATE_CPP_
#define DATE_CPP_
#include <string>
#include <cstdio>

class Date {

 public:
  void setDate(int year, int month, int day);
  int year() const;
  int month() const;
  int day() const;

  std::string toString() const {
    const int length_of_date_string = 10;

    char date_string[length_of_date_string + 1];
    snprintf(date_string,
            length_of_date_string + 1,
            "%04d-%02d-%02d",
            year_, month_, day_);

    return std::string(date_string);
  }

  void increment();
  void decrement();

 private:
  int year_;
  int month_;
  int day_;

  int daysOfMonth(int year, int month) const;
};

int Date::daysOfMonth(int year,int month) const{ 
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


void Date::setDate(int year, int month, int day){
  	year_=year;
  	month_=month;
  	day_=day;
}

int Date::year() const{
  	return year_;
  }
int Date::month() const{
  	return month_;
  }
int Date::day() const{
  	return day_;
  }

void Date::increment(){
			day_++;
			if(day_>daysOfMonth(year_,month_)){
				day_=1;
				month_++;
				if(month_>12){
					month_=1;
					year_++;
				}
			}
		}
void Date::decrement(){
			day_--;
			if(day_==0){
				month_--;
				if(month_==0){
					month_=12;
					year_--;
				}
				day_=daysOfMonth(year_,month_);
			}
		}

#endif
