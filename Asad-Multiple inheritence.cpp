#include <iostream>
#include <string>
using namespace std;

//base class 1
class Vehicle{
	protected:
		string brand , modelYear;
		
	public:
		//default constructor
		Vehicle() : brand("N/A") , modelYear("****") {
			cout<<"Vehicle default constructor called.\n";
		}
		
		//parameterized constructor
		Vehicle(const string& b , const  string& mY)
		: brand(b) , modelYear(mY) {
			cout<<"Vehicle parameterized constructor called.\n";
		}

		//member function
		void displayVehicleInfo() const {
			cout<<"\nBrand\t\t:\t"<<brand;
			cout<<"\nModel Year\t:\t"<<modelYear;
		}
};

//base class 2
class GPS {
	protected:
		float latitude , longitude;
	
	public:
		//default constructor
		GPS() : latitude(0.0f) , longitude(0.f) {
			cout<<"GPS default constructor called.\n";
		}
		
		//parameterized constructor
		GPS(float lat , float lon) : latitude(lat) , longitude(lon) {
			cout<<"GPS parameterized constructor called.\n";
		}
		
		//member function
		void displayGPS() const {
			cout<<"\nLatitude\t:\t"<<latitude;
			cout<<"\nLongitude\t:\t"<<longitude;
		}
};

//derived class from both class 1 & 2
class SmartCar : protected Vehicle , protected GPS {
	private:
		string ownerName;
		
	public:
		//default constructor
		SmartCar(){
			setOwnerName("N/A");
			cout<<"SmartCar default constructor called.\n";
		}
		
		//parameterized constructor
		SmartCar(const string& b , const string& mY , float lat , float lon , const string& oN)
		: Vehicle(b , mY) , GPS(lat , lon) {
			setOwnerName(oN);
			cout<<"SmartCar parameterized constructor called.\n";
		}
		
		//setter
		void setOwnerName(const string& oN){
			ownerName = oN;
		}
		
		//getter
		string getOwnerName() const {
			return ownerName;
		}
		
		//member function
		void displaySmartCarInfo() const {
			displayVehicleInfo();
			displayGPS();
			cout<<"\nOwner Name\t:\t"<<getOwnerName()<<endl;
		}
};


int main(){
	cout<<"-----Smart car object with default values-----\n\n";
	SmartCar car1;
	car1.displaySmartCarInfo();
	cout<<"\n-----Smart car object with set values-----\n\n";
	SmartCar car2("Tesla" , "2024" , 56.73 , -23.54 , "Asad Mehmood");
	car2.displaySmartCarInfo();
	
	return 0;
}
