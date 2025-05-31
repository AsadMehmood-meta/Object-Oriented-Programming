#include<iostream>
#include<string>

using namespace std;

class Student{
	private:
		string name;
		int rollNo;
		float gpa;
		
	public:
		//default constructor
		Student() : name("No name") , rollNo(0) , gpa(0.0f) {}
		
		//parameterized constructor
		Student(const string& n , int rN , float g)
		: name(n) , rollNo(rN) , gpa(g) {}
		
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
			cout<<"\Name : "<<name<<"\tRoll No : "<<rollNo<<"\tGPA : "<<gpa;
		}
};

void sortStudentByGPA(Student** students , int size); //funnction to sort student by gpa
void displayStudents(Student** students , int size);	//function display students details

int main(){
	int size = 7;
	string names[size] = {"Ali" , "Ahmed" , "Asad" , "Moiz" , "Bilal", "Sohaib" , "Waqas"};
	int rollNumbers[size] = {1001 , 1002 , 1003 , 1004 , 1005 , 1006 , 1007};
	float GPA[size] = {2.23 , 2.5 , 3.8 , 3.65 , 2.98 , 3.45 , 2.87};
	
	Student** students = new Student* [size];
	
	for(int i=0 ; i<size ; i++){
		students[i] = new Student();
		students[i]->setName(names[i]);
		students[i]->setRollNo(rollNumbers[i]);
		students[i]->setGpa(GPA[i]);
	}
	
	sortStudentByGPA(students , size);
	
	cout<<"-----Students sorted by GPA-----\n\n";
	
	displayStudents(students , size);
	
	cout<<"\n\n----------------------------\n\n";
	
	return 0;
}

void sortStudentByGPA(Student** students , int size){
	for(int i=0 ; i<size-1 ; i++){
		for(int j=i+1 ; j<size ; j++){
			if(students[i]->getGpa() < students[j]->getGpa()){
				swap(students[i] , students[j]);
			}
		}
	}
}

void displayStudents(Student** students , int size){
	for(int i=0 ; i<size ; i++){
		cout<<"Student #"<<i+1<<"\t:\t";
		students[i]->displayStudentsDetails();
		cout<<endl;	
	}
}
