#include<iostream>
#include<string>

using namespace std;

//parent class
class University{
	protected:
		string uniName , address;
		
	public:
		//default constructor
		University() : uniName("No name") , address("Nil") {}
		
		//parameterized constructor
		University(const string& uN , const string& ad)
		: uniName(uN) , address(ad) {}
		
		//setters
		void setUniName(const string& uN){
			uniName = uN;
		}
		void setAddress(const string& ad){
			address = ad;
		}
		
		//getters
		string getUniName()const{
			return uniName;
		}
		string getAddress()const{
			return address;
		}
		
		
		//display function
		void displayUniversityDetails()const{
			cout<<"\nUniversity Name\t\t:\t"<<uniName;
			cout<<"\nUniversity Address\t:\t"<<address;
		}
};

//child class
class Student : protected University{
	private:
		string name;
		int rollNo;
		float gpa;
		
	public:
		//default constructor
		Student() : name("No name") , rollNo(0) , gpa(0.0f) {}
		
		//parameterized constructor
		Student(const string& uN , const string& ad , const string& n , int rN , float g)
		: University(uN , ad) , name(n) , rollNo(rN) , gpa(g) {}
		
		//setters
		void setName(const string& n){
			name = n;
		}
		void setRollNo(int rN){
			rollNo = rN;
		}
		void setGpa(float g){
			gpa = g;
		}
		
		//getters
		string getName()const{
			return name;
		}
		int getRollNo()const{
			return rollNo;
		}
		float getGpa()const{
			return gpa;
		}
		
		//display function
		void displayStudentsDetails()const{
			displayUniversityDetails();
			cout<<"\nStudent name\t\t:\t"<<name;
			cout<<"\nRoll No\t\t\t:\t"<<rollNo;
			cout<<"\nGPA\t\t\t:\t"<<gpa;
		}
};


int main(){
	//student1(university name , university address , student name , student roll# , student GPA)
	
	Student student1("UIT" , "University Road, Karachi." , "Asad Mehmood" , 1001 , 3.25);
	
	cout<<"Student # 1 details:";
	student1.displayStudentsDetails();
	
	
	
	return 0;
}
