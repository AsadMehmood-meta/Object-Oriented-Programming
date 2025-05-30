#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxCourses = 1;
const int maxStudent = 5;

//class 2
class Course{
	private:
		string courseName , courseID;
		int totalMarks;
		float obtainedMarks;
	
	public:
		//default constructor
		Course() : courseName("No course") , courseID("***") , obtainedMarks(0.0f) , totalMarks(75) {}
		
		//parameterized constructor
		Course(const string& cN , const string& cID)
		: courseName(cN) , courseID(cID) , obtainedMarks(rand() % 26 + 50) , totalMarks(75) {}
		
		//destructor 
		~Course(){}
		
		//setters
		void setCourseName(const string& cN){
			courseName = cN;
		}
		void setCourseID(const string& cID){
			courseID = cID;
		}
		void setObtainedMarks(float oM){
			obtainedMarks = oM;
		}
		void setTotalMarks(int tM){
			totalMarks = tM;
		}
		
		//getters
		string getCourseName()const{
			return courseName;
		}
		string getCourseID()const{
			return courseID;
		}
		float getObtainedMarks()const{
			return obtainedMarks;
		}
		int getTotalMarks()const{
			return totalMarks;
		}
		
		//display function
		void displayCourseInfo()const{
			cout<<"\nCourse name\t:\t"<<getCourseName();
			cout<<"\nCourse ID\t:\t"<<getCourseID();
			cout<<"\nMarks\t\t:\t"<<getObtainedMarks()<<"/"<<getTotalMarks();
		}
};

//class 3
class Student{
	private:
		string studentName , studentEmail;
		int courseCount;
		Course courses[maxCourses];
		
	public:
		//default constructor
		Student() : studentName("No student") , studentEmail("No email") , courseCount(0) {}
		
		//parameterized constructor
		Student(const string& sN , const string& sEm)
		: studentName(sN) , studentEmail(sEm) , courseCount(0) {}
		
		//destructor
		~Student(){}
		
		//setters
		void setStudentName(const string& sN){
			studentName = sN;
		}
		void setStudentEmail(const string& sEm){
			studentEmail = sEm;
		}
		
		//getters
		string getStudentName()const{
			return studentName;
		}
		string getStudentEmail()const{
			return studentEmail;
		}
		
		//add course
		void addCourse(const Course c){
			if(courseCount<maxCourses){
				courses[courseCount++] = c;
			} else{
				cout<<"\nCannot add more courses.\n";
			}
		}
		
		
		//total obtained marks in all courses
		float getTotalObtainedMarks(){
			float total =0;
			for(int i=0 ; i<courseCount ; i++){
				total += courses[i].getObtainedMarks();
			}
			return total;
		}
		
		//display function
		void displayStudentDetails()const{
			cout<<"\nStudent Name\t:\t"<<getStudentName();
			cout<<"\nStudent Email\t:\t"<<getStudentEmail();
			for (int i=0 ; i<courseCount ; i++){
				courses[i].displayCourseInfo();
			}
		}
};


//class 1
class Teacher{
	private:
		string name , email;
		Student students[maxStudent];
		int studentCount;
	
	public:
		//default constructor
		Teacher() : name("No Name") , email("No email") , studentCount(0) {}
		
		//parameterized constructor
		Teacher(const string& tn , const string& tEm)
		: name(tn) , email(tEm) , studentCount(0) {}
		
		//destructor
		~Teacher(){}
		
		//setter
		void setName(const string& tn){
			name = tn;
		}
		
		void setEmail(const string& tEm){
			email = tEm;
		}
		
		//getters
		string getName()const{
			return name;
		}
		
		string getEmail()const{
			return email;
		}
		
		//aggregate students
		void addStudent(const Student s){
			if(studentCount<maxStudent){
				students[studentCount++] = s;
			} else{
				cout<<"\nCannot add more student.\n";
			}
		}
		
		//sorting function
		void sortStudentsByMarks() {
  		  for (int i = 0; i < studentCount - 1; i++) {
 		       for (int j = i + 1; j < studentCount; j++) {
   			         if (students[i].getTotalObtainedMarks() < students[j].getTotalObtainedMarks()) {
   			         	swap(students[i] , students[j]);
         			   }
      			  }
   			 }
		}
		
		//display function
		void displayTeacherInfo()const{
			cout << "\n========== Teacher Info ==========\n";
			cout<<"\nTeacher name\t:\t"<<getName();
			cout<<"\nTeacher email\t:\t"<<getEmail();
			for (int i=0 ; i<studentCount ; i++){
				cout<<endl<<endl;
				students[i].displayStudentDetails();
			}
			 cout << "\n==================================\n";
		}
}; 





int main(){
	Teacher t("Prof Ahmed" , "prof.ahmed@gmail.com");
	
	Student s1("Asad" , "asad@gmail.com");
	Student s2("Usama" , "usama@gmail.com");
	Student s3("Anus" , "anus@gmail.com");
	
	Course cS1("oops" , "CS 2001");
	Course cS2("oops" , "CS 2001");
	Course cS3("oops" , "CS 2001");
	
	s1.addCourse(cS1);
	s2.addCourse(cS2);
	s3.addCourse(cS3);
	
	t.addStudent(s1);
	t.addStudent(s2);
	t.addStudent(s3);
	
	t.sortStudentsByMarks();
	t.displayTeacherInfo();
	
}
