#include<iostream>
#include<string>

using namespace std;

class Book{
	private:
		string title , author;
		float price;
		
	public:
		//default constructor
		Book() : title("No title") , author("No author") , price(0.0f) {}
		
		//parameterized constructor
		Book(const string& t , const string& a , float p)
		: title(t) , author(a) , price(p) {}
		
		//setters
		void setTitle(const string& t){
			title = t;
		}
		void setAuthor(const string& a){
			author = a;
		}
		void setPrice(float p){
			price = p;
		}
		
		//getters
		string getTitle()const{
			return title;
		}
		string getAuthor()const{
			return author;
		}
		float getPrice()const{
			return price;
		}
		
		//calculate discount of 20%
		float calculateDiscount(){
			float discountedPrice = price*0.8;
			return discountedPrice;
		}
		
		//display function
		void displayBookInfo()const{
			cout<<"\nTitle\t:\t"<<title;
			cout<<"\nAuthor\t:\t"<<author;
			cout<<"\nPrice\t:\t"<<price<<" Pkr";
		}
};


int main(){
	Book b1("Intro to Oops" , "Prof. Ahmed" , 750);
	cout<<"-----Book details-----\n";
	b1.displayBookInfo();
	
	cout<<"\n\nDiscounted amount (20% discount) : "<<b1.calculateDiscount();
	
	return 0;
}
