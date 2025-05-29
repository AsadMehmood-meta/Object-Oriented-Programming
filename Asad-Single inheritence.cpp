#include <iostream>
#include <string>
using namespace std;

//Base class
class Employee{
	protected:
		string name , empID;
		float salary;
	
	public:
		//default constructor
		Employee()
		: name("N/A") , empID("***") , salary(0) {
			cout<<"Employee default constructor called.\n";
		}
		
		//parameterized constructor called
		Employee(string n , string id , float s)
		: name(n) , empID(id) , salary(s) {
			cout<<"Employee parameterized constructor called.\n";
		}
		
		//member function
		void displayInfo(){
			cout<<"\nEmployee Name\t:\t"<<name;
			cout<<"\nEmployee ID\t:\t"<<empID;
			cout<<"\nSalary\t\t:\t"<<salary;
		}
};

//derived class from Employee class
class Manager : protected Employee{
	private:
		string dept;
	
	public:
		//default constructor 
		Manager()
		: dept("Default department"){
			cout<<"Manager default constructor called.\n";
		}
		
		//manager parameterized constructor
		Manager(const string& n , const string& id , float s , string d)
		: Employee( n , id , s) , dept(d) {
			cout<<"Manager parameterized constructor called.\n";
		}
		
		//setter
		void setDept(string d){
			dept = d;
		}
		
		//getter
		string getDept(){
			return dept;
		}
		
		//member function
		void displayManagerInfo(){
			displayInfo();
			cout<<"\nDepartment\t:\t"<<getDept()<<endl<<endl;
		}
};


int main(){
	Manager manager1;	//create object
	manager1.displayManagerInfo();	//display default values
	
	Manager manager2("Asad Mehmood" , "1001" , 75000 , "IT");	//set values
	manager2.displayManagerInfo();	//display after set values
	
	return 0;
}
