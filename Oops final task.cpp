#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 10;

// airport class
class Airport {
private:
    string name, city, country, airportCode;

public:
    // defualt constructor
    Airport() : name("N/A"), city("N/A"), country("N/A"), airportCode("N/A") {}

    // destructorr
    ~Airport() {}

    // settrs
    void setName(const string& n) { name = n; }
    void setCity(const string& c) { city = c; }
    void setCountry(const string& c) { country = c; }
    void setAirportCode(const string& code) { airportCode = code; }

    // gettrs
    string getName() const { return name; }
    string getCity() const { return city; }
    string getCountry() const { return country; }
    string getAirportCode() const { return airportCode; }

    void input() {
        cout << "enter airport name: ";
        cin.ignore();
        getline(cin, name);
        cout << "enter city: ";
        getline(cin, city);
        cout << "enter country: ";
        getline(cin, country);
        cout << "enter airport code: ";
        getline(cin, airportCode);
    }

    void display() const {
        cout << "airport name: " << name << "\ncity: " << city
             << "\ncountry: " << country << "\ncode: " << airportCode << endl;
    }

    string toString() const {
        return name + "," + city + "," + country + "," + airportCode;
    }
};

// airline class
class Airline {
private:
    string name, airlineCode, originCountry;

public:
    // defualt constructor
    Airline() : name("N/A"), airlineCode("N/A"), originCountry("N/A") {}

    // destructer
    ~Airline() {}

    // seters
    void setName(const string& n) { name = n; }
    void setCode(const string& c) { airlineCode = c; }
    void setCountry(const string& c) { originCountry = c; }

    // geters
    string getName() const { return name; }
    string getCode() const { return airlineCode; }
    string getCountry() const { return originCountry; }

    void input() {
        cout << "enter airline name: ";
        cin.ignore();
        getline(cin, name);
        cout << "enter airline code: ";
        getline(cin, airlineCode);
        cout << "enter origin country: ";
        getline(cin, originCountry);
    }

    void display() const {
        cout << "airline name: " << name << "\ncode: " << airlineCode
             << "\norigin country: " << originCountry << endl;
    }

    string toString() const {
        return name + "," + airlineCode + "," + originCountry;
    }
};

// iata organization class
class IATA_Organization {
private:
    string orgName, directorName, directorEmail;

public:
    // defualt constructer
    IATA_Organization() : orgName("N/A"), directorName("N/A"), directorEmail("N/A") {}

    // destroctor
    ~IATA_Organization() {}

    // seter functions
    void setOrgName(const string& o) { orgName = o; }
    void setDirectorName(const string& d) { directorName = d; }
    void setDirectorEmail(const string& e) { directorEmail = e; }

    // geter functions
    string getOrgName() const { return orgName; }
    string getDirectorName() const { return directorName; }
    string getDirectorEmail() const { return directorEmail; }

    void inputDirectorInfo() {
        cout << "enter iata organization name: ";
        getline(cin, orgName);
        cout << "enter director name: ";
        getline(cin, directorName);
        cout << "enter director email: ";
        getline(cin, directorEmail);
    }

    void displayDirectorInfo() const {
        cout << "\nIATA director info\n";
        cout << "organization: " << orgName << "\ndirector: " << directorName
             << "\nemail: " << directorEmail << endl;
    }
};

// write line to file
void saveLineToFile(const string& filename, const string& data) {
    ofstream fout(filename.c_str(), ios::app);
    fout << data << endl;
    fout.close();
}

// delet a line from file by key
void deleteLineFromFile(const string& filename, const string& key) {
    ifstream fin(filename.c_str());
    ofstream fout("temp.txt");
    string line;
    while (getline(fin, line)) {
        if (line.find(key) == string::npos)
            fout << line << endl;
    }
    fin.close();
    fout.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

// updaet a line in file
void updateLineInFile(const string& filename, const string& key, const string& newLine) {
    ifstream fin(filename.c_str());
    ofstream fout("temp.txt");
    string line;
    while (getline(fin, line)) {
        if (line.find(key) != string::npos)
            fout << newLine << endl;
        else
            fout << line << endl;
    }
    fin.close();
    fout.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

// show all contants of file
void showFile(const string& filename) {
    ifstream fin(filename.c_str());
    string line;
    cout << "\ncontents of " << filename << "\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

// add menue for airport and airline
void addMenu(Airport airports[], Airline airlines[], int& airportCount, int& airlineCount) {
    int typeChoice;
    cout << "1. add airport\n2. add airline\nchoose: ";
    cin >> typeChoice;
    switch (typeChoice) {
        case 1:
            if (airportCount < MAX) {
                airports[airportCount].input();
                saveLineToFile("airport.txt", airports[airportCount].toString());
                airportCount++;
            } else {
                cout << "airport limt reached\n";
            }
            break;
        case 2:
            if (airlineCount < MAX) {
                airlines[airlineCount].input();
                saveLineToFile("airline.txt", airlines[airlineCount].toString());
                airlineCount++;
            } else {
                cout << "airline limt reached\n";
            }
            break;
        default:
            cout << "invalid opton\n";
    }
}

// delet menu for airport or airline
void deleteMenu() {
    int typeChoice;
    string code;
    cout << "1. delete airport\n2. delete airline\nchoose: ";
    cin >> typeChoice;
    cin.ignore();
    cout << "enter code to delete: ";
    getline(cin, code);
    if (typeChoice == 1) {
        deleteLineFromFile("airport.txt", code);
    } else if (typeChoice == 2) {
        deleteLineFromFile("airline.txt", code);
    } else {
        cout << "invalid optoin\n";
    }
}

// updat menu for records
void updateMenu() {
    int typeChoice;
    string code;
    cout << "1. update airport\n2. update airline\nchoose: ";
    cin >> typeChoice;
    cin.ignore();
    cout << "enter code to update: ";
    getline(cin, code);
    if (typeChoice == 1) {
        Airport temp;
        temp.input();
        updateLineInFile("airport.txt", code, temp.toString());
    } else if (typeChoice == 2) {
        Airline temp;
        temp.input();
        updateLineInFile("airline.txt", code, temp.toString());
    } else {
        cout << "invalid opton\n";
    }
}

// show all data from files or director info
void showMenu(const IATA_Organization& iata) {
    int typeChoice;
    cout << "1. show airports\n2. show airlines\n3. show director info\nchoose: ";
    cin >> typeChoice;
    switch (typeChoice) {
        case 1:
            showFile("airport.txt");
            break;
        case 2:
            showFile("airline.txt");
            break;
        case 3:
            iata.displayDirectorInfo();
            break;
        default:
            cout << "invaled choice\n";
    }
}

int main() {
	cout<<"Member # 1\t:\tAsad Mehmood\n";
    cout<<"Member # 2\t:\tOsama Bin Khalid\n\n";
	
    IATA_Organization iata;
    iata.inputDirectorInfo();

    Airport airports[MAX];
    Airline airlines[MAX];
    int airportCount = 0, airlineCount = 0;

    int mainChoice;
    
    

    do {
        cout << "\nIATA director menu\n";
        cout << "1. add\n2. delete\n3. update\n4. show info\n0. exit\n";
        cout << "enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                addMenu(airports, airlines, airportCount, airlineCount);
                break;
            case 2:
                deleteMenu();
                break;
            case 3:
                updateMenu();
                break;
            case 4:
                showMenu(iata);
                break;
            case 0:
                cout << "exiting program\n";
                break;
            default:
                cout << "invalid choise\n";
        }

    } while (mainChoice != 0);

    return 0;
}

