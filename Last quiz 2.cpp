#include<iostream>
#include<string>

using namespace std;

class Teacher{
	private:
		string name;
		int age;
	
	public:
		//default constructor
		Teacher() : name("No Name") , age(0) {}
		
		//parameterized constructor
		Teacher(const string& n , int a)
		: name(n) , age(a) {}
		
		//destructor
		~Teacher(){}
		
		//setter
		void setName(const string& n){
			name = n;
		}
		void setAge(int a){
			age = a;
		}
		
		//getters
		string getName()const{
			return name;
		}	
		int getAge()const{
			return age;
		}

		//display function
		void displayTeacherInfo()const{	
			cout<<"Name\t:\t"<<getName()<<"\t\tAge\t:\t"<<getAge();
		}
}; 

int main(){
	string names[15] = {"Ali" , "Ahmed" , "Usama" , "Mehmood" , "Waqas" , "Fahad" , "Mohib" , "Aqib" , "Channa" , "Zaheer" , "Shamim" , "Vicky" , "Ansab" , "Bilal" , "Zeeshan"};
	int ages[15] = {15,54,84,21,65,24,29,35,32,17,16,17,38,47,51};
	int size = 15;
	
	Teacher teachers[15];
	
	//assigning values in teachers objects
	for(int i=0 ; i<size ; i++){
		teachers[i].setName(names[i]);
		teachers[i].setAge(ages[i]);
	}
	
	//sorting 
  	for (int i = 0; i < size - 1; i++) {
 		for (int j = i + 1; j < size; j++) {
   		     if (teachers[i].getAge() > teachers[j].getAge()) {
   		    	swap(teachers[i] , teachers[j]);
			}
		}
	}
	
	//display 
	cout << "\n========== Teacher Info ==========\n";

	for(int i=0 ; i<size ; i++){
		cout<<"Teacher # "<<i+1<<":\t";
		teachers[i].displayTeacherInfo();
		cout<<endl;
	}

	cout << "==================================\n";
	
	return 0;
}




