#include <iostream>
#include <string>
using namespace std;

class  Employee{
	public:
		string name;
		void setName(const string&);
		string getName();
		virtual double getIncome(){		};
		virtual  ~Employee(){
		}
};

class  Technician : public Employee{
	public:
		int hour;
		double hourWage;
		void setHour(int);
		void setHourWage(double);
		double getIncome();

		virtual  ~Technician(){
			
		}
};
class  Salesman : public Employee{
	public:
		double salesVolume;
		double proportion;
		void setSalesVolume(double);
		void setProportion(double);
		double getIncome();

		virtual ~Salesman(){
			
		}	
};
class  Manager : public Employee{
	public:
		int monthlySalary;
		void setMonthlySalary(int);
		double getIncome();

		virtual ~Manager(){
			
		}	
};
class  Salesmanager : public Salesman , public Manager{
	public:
		double getIncome();

		virtual ~Salesmanager(){
			
		}
};
