#include <iostream>
#include <string>
using namespace std;

//base class
class Person{
	protected:
		string name;
		int age;
		
	public:
		//default constructor
		Person() : name("No name") , age(0) {
		}
		
		//parameterized constructor
		Person(const string& n , int a)
		: name(n) , age(a){
//			cout<<"Person parameterized constructor called.\n";
		}
		
		//destructor
		virtual ~Person(){
			cout<<"\nPerson destructor called.";
		}

		//display function
		void displayPersonInfo()const{
			cout<<"\nName\t\t:\t"<<name;
			cout<<"\nAge\t\t:\t"<<age;
		}
};

//level 1 derived class 1
class Employee : virtual protected Person{
	protected:
		string empID , dept;
	
	public:
		//default constructor
		Employee() : empID("####") , dept("No department") {
//			cout<<"Employee default constructor called.\n";
		}
		
		//parameterized constructor
		Employee(const string& n , int a , const string& e , const string& d)
		: Person(n , a) , empID(e) , dept(d){
//			cout<<"Employee parameterized constructor called.\n";
		}
		
		//destructor
		virtual ~Employee(){
			cout<<"\nEmployee destructor called.";
		}

		//display function
		void displayEmployeeInfo()const{
			displayPersonInfo();
			cout<<"\nEmployee ID\t:\t"<<empID;
			cout<<"\nDepartment\t:\t"<<dept;
		}
};

//level 1 derived class 2
class Student : virtual protected Person{
	protected:
		string studentID , major;
		
	public:
		//default constructor
		Student() : studentID("####") , major("No major") {
//			cout<<"Student default constructor called.\n";
		}
		
		//parameterized constructor
		Student(const string& n , int a , const string& s , const string& m)
		: Person(n , a) , studentID(s) , major(m){
//			cout<<"Student parameterized constructor called.\n";
		}
		
		//destructor
		virtual ~Student(){
			cout<<"\nStudent destructor called.";
		}

		//display function
		void displayStudentInfo()const{
			displayPersonInfo();
			cout<<"\nStudent ID\t:\t"<<studentID;
			cout<<"\nMajor\t\t:\t"<<major;
		}
};

//level 2 derived class 1 from Employee
class Teacher : protected Employee{
	protected:
		string subject;
		float salary;
			
	public:
		//default constructor
		Teacher() : subject("No subject") , salary(0.0f) {
//			cout<<"Teacher default constructor called.\n";
		}
		
		//parameterized contructor
		Teacher(const string& n , int a , const string& e , const string& d , const string& sub , float sal)
		: Employee(n , a , e , d) , subject(sub) , salary(sal){
//			cout<<"Teacher parameterized constructor called.\n";
		}
		
		//destructor
		~Teacher(){
			cout<<"\nTeacher destructor called.";
		}
		
		//display function
		void displayTeacherInfo()const{
			displayEmployeeInfo();
			cout<<"\nSubject\t\t:\t"<<subject;
			cout<<"\nSalary\t\t:\t"<<salary;
		}
};

//level 2 derived class 2 from Employee
class Administrator : protected Employee{
	protected:
		string role , officeNo;
		
	public:
		//default constructor
		Administrator() : role("No role") , officeNo("No office") {
//			cout<<"Aministrator default constructor called.\n";
		}
		
		//parameterized constructor
		Administrator(const string& n , int a , const string& e , const string& d , const string& r , const string& oNo)
		: Employee(n , a , e , d) , role(r) , officeNo(oNo){
//			cout<<"Aministrator parameterized constructor called.\n";
		}
		
		//destructor
		~Administrator(){
			cout<<"\nAdministrator destructor called.";
		}

		//display function
		void displayAdministratorInfo()const{
			displayEmployeeInfo();
			cout<<"\nRole\t\t:\t"<<role;
			cout<<"\nOffice No\t:\t"<<officeNo;
		}
};

//level 2 derived class 1 from Student
class Undergraduate : protected Student{
	protected:
		int year;
		float GPA;
		
	public:
		//default constructor
		Undergraduate() : year(0) , GPA(0.0f) {
//			cout<<"Undergradute default constructor called.\n";
		}
		
		//parameterized constructor
		Undergraduate(const string& n , int a , const string& s , const string& m , int y , float gpa)
		: Student(n , a , s , m) , year(y) , GPA(gpa){
//			cout<<"Undergradute parameterized constructor called.\n";
		}
		
		//destructor
		~Undergraduate(){
			cout<<"\nUndergradute destructor called.";
		}

		//display function
		void displayUndergraduateInfo()const{
			displayStudentInfo();
			cout<<"\nYear\t\t:\t"<<year;
			cout<<"\nGPA\t\t:\t"<<GPA;
		}
};

//level 2 derived class 2 from Student
class Graduate : protected Student{
	protected:
		string researchArea , advisor;
		
	public:
		//default constructor
		Graduate() : researchArea("No research area") , advisor("No advisor") {
//			cout<<"Graduate default constructor called.\n";
		}
		
		//parameterized constructor called
		Graduate(const string& n , int a , const string& s , const string& m , const string& rA , const string& ad)
		: Student(n , a , s , m) , researchArea(rA) , advisor(ad){
//			cout<<"Graduate paraeterized constructor called.\n";
		}
		
		//destructor
		~Graduate(){
			cout<<"\nGraduate destructor called.";
		}

		//display function
		void displayGraduateInfo()const{
			displayStudentInfo();
			cout<<"\nResearch Area\t:\t"<<researchArea;
			cout<<"\nAdvisor\t\t:\t"<<advisor;
		}
};

//level 3 derived from Teacher and Graduate
class TeachingAssistant : protected Teacher , protected Graduate{
	private:
		int hoursPerWeek;
		
	public:
		//default constructor
		TeachingAssistant(){
			setHoursPerWeek(0);
//			cout<<"TeachingAssistant default constructor called.\n";
		}
		
		//parameterized constructor
		TeachingAssistant(const string& n , int a , const string& e , const string& d , const string& sub , float sal , const string& s , const string& m , const string& rA , const string& ad , int hpw)
		: Person(n , a) , Teacher(n , a , e , d , sub , sal) , Graduate(n , a , s , m , rA , ad) , hoursPerWeek(hpw){
//			cout<<"TeachingAssistant parameterized  constructor called.\n";
		}
		
		//destructor
		~TeachingAssistant(){
			cout<<"\nTeachingAssistant destructor called.";
		}
		
		//setter
		void setHoursPerWeek(int hpw){
			hoursPerWeek = hpw;
		}
		
		//getter
		int getHoursPerWeek()const{
			return hoursPerWeek;
		}
		
		//display function
		void displayTeachingAssistantInfo()const{
			displayEmployeeInfo();
			cout<<"\nSubject\t\t:\t"<<subject;
			cout<<"\nSalary\t\t:\t"<<salary;
			cout<<"\nStudent ID\t:\t"<<studentID;
			cout<<"\nMajor\t\t:\t"<<major;
			cout<<"\nResearch Area\t:\t"<<researchArea;
			cout<<"\nAdvisor\t\t:\t"<<advisor;
			cout<<"\nHours/week\t:\t"<<getHoursPerWeek();
		}
};


int main(){
	cout<<"-----Teacher Assistant Info (with default values)-----\n";
	TeachingAssistant TA1;
	TA1.displayTeachingAssistantInfo();
	
	cout<<"\n\n-----Teacher Assistant Info-----\n";
	TeachingAssistant TA2("Asad Mehmood" , 29 , "E-1001" , "Computer Science" , "OOPS" , 75000 , "S-2001" , "Artificial Intelligence" , "Machine Learning" , "Dr. Khan" , 20);
	TA2.displayTeachingAssistantInfo();
	
	cout<<endl<<endl;
	
	return 0;
}
