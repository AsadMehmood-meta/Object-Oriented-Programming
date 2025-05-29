#include <iostream>
#include <string>
using namespace std;

//root class
class Book{
	protected:
		string title , author , ISBN;
		
	public:
		//default constructor
		Book(): title("No Title") , author("No Name") , ISBN("****-****"){
			cout<<"Book default constructor called.\n";
		}
		
		//parameterized constructor
		Book(const string& t , const string& a , const string isbn)
		: title(t) , author(a) , ISBN(isbn) {
			cout<<"Book parameterized constructor called.\n";
		}
		
		//destructor
		~Book(){
			cout<<"\nBook destructor called.";
		}
		
		//display function
		void displayBookInfo()const{
			cout<<"\nTitle\t\t:\t"<<title;
			cout<<"\nAuthor\t\t:\t"<<author;
			cout<<"\nISBN\t\t:\t"<<ISBN;
		}
};

//parent class from Book
class PrintedBook : protected Book{
	protected:
		int pageCount;
		float weight;
	
	public:
		//default constructor
		PrintedBook() : pageCount(0) , weight(0.0f){
			cout<<"PrintedBook default constructor called.\n";
		}
		
		//parameterized constructor
		PrintedBook(const string& t , const string& a , const string& isbn , int pC , float w)
		: Book(t , a , isbn) , pageCount(pC) , weight(w) {
			cout<<"PrintedBook parameterized constructor called.\n";
		}
		
		//destructor
		~PrintedBook(){
			cout<<"\nPrintedBook destructor called.";
		}

		//display function
		void displayPrintedBookInfo()const{
			displayBookInfo();
			cout<<"\nPages\t\t:\t"<<pageCount;
			cout<<"\nWeight\t\t:\t"<<weight<<" grams";
		}
};

//child class from PrintedBook
class EBook : protected PrintedBook{
	private:
		float fileSize;
		string format;
	
	public:
		//default constructor
		EBook(){
			setFileSize(0.0f);
			setFormat("N/A");
			cout<<"EBook default constructor called.\n";
		}
		
		//parameterized constructor
		EBook(const string& t , const string& a , const string isbn , int pC , float w , float fS , const string& f)
		: PrintedBook(t , a , isbn , pC , w){
			setFileSize(fS);
			setFormat(f);
			cout<<"EBook parameterized constructor called.\n";
		}
		
		//destructor
		~EBook(){
			cout<<"\nEBook destructor called.";
		}
		
		//setters
		void setFileSize(float fS){
			fileSize = fS;
		}
		void setFormat(const string& f){
			format = f;
		}
		
		//getters
		float getFileSize()const{
			return fileSize;
		}
		string getFormat()const{
			return format;
		}
		
		//display function
		void displayEBookInfo()const{
			displayPrintedBookInfo();
			cout<<"\nFile Size\t:\t"<<fileSize<<" MB";
			cout<<"\nFormat\t\t:\t"<<format;
		}
};

int main(){
	cout<<"-----EBook object with default values-----\n\n";
	EBook book1;
	book1.displayEBookInfo();
	
	cout<<"\n\n-----EBook object with set values-----\n\n";
	EBook book2("C++ Intro" , "Asad Mehmood" , "5427-672" , 573 , 857.23 , 5.36 , "PDF");
	book2.displayEBookInfo();
	
	cout<<endl;
	
	return 0;
}
