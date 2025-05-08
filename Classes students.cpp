#include <iostream>

using namespace std;

class students{
	string name;
	int marks;

public:
	void getData(string name1 , int marks1){
		name = name1;
		marks = marks1;
	}
	
	void display(){
		cout<<"Name: "<<name<<"\tMarks: "<<marks;
	}
};

void takeInput(students [], int );
void displayStudents(students [], int );

int main(){
	int size = 0;
	cout<<"How many students in your class: ";
	cin>>size;
	
	students s[size];
	
	takeInput(s, size);
	displayStudents(s, size);
}

void takeInput(students s[], int size){
	for(int i=0 ; i<size ; i++){
		string name;
		int marks=0;
		
		cout<<"Enter name of student "<<i+1<<": ";
		cin>>name;
		
		cout<<"Enter marks of student "<<i+1<<": ";
		cin>>marks;
		
		s[i].getData(name ,marks);
		
		cout<<endl;		
	}
}

void displayStudents(students s[], int size){
	for(int i=0 ; i<size ; i++){
		cout<<"Student: "<<i+1<<endl;
		s[i].display();
		cout<<endl;
	}
}
