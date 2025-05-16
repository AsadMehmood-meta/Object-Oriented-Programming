#include <iostream>

using namespace std; 
class Box {
private:
    int length, width, height;
    int* volume; // dynamically allocated

public:
    // Constructor
    Box() {
        length = 0;
        width = 0;
        height = 0;
        volume = new int(0); // default volume set to 0
    }

    // Setter function to set dimensions and calculate volume
    void setDimensions(int l, int w, int h) {
        this->length = l;
        this->width = w;
        this->height = h;

        // Allocate memory for volume and calculate
        // deferencing accessing value at volumne
        //Recap
        //int a = 10;
        //int *ptr = &a;
        //int value = *ptr;  /
        *this->volume = length * width * height;
    }

    // Copy Constructor (deep copy)
    Box(const Box& other) {
        this->length = other.length;
        this->width = other.width;
        this->height = other.height;

        this->volume = new int(*other.volume);
    }

    // Destructor
    ~Box() {
        delete volume;
        cout << "Destructor called for Box with volume: " << *volume << endl;
    }

    // Display function
    void display() const {
        cout << "Dimensions: " << length << "x" << width << "x" << height
             << ", Volume: " << *volume << endl;
    }
};

int main() {
    const int numBoxes = 3;
    Box boxes[numBoxes];

    // Loop to get user input for each box
    for (int i = 0; i < numBoxes; ++i) {
        int l, w, h;
        cout << "Enter dimensions for Box " << i + 1 << " (length width height): ";
        cin >> l >> w >> h;

        // Use setter to set the dimensions and calculate the volume
        boxes[i].setDimensions(l, w, h);
    }

    // Display all the boxes
    for (int i = 0; i < numBoxes; ++i) {
        cout << "Box " << i + 1 << ": ";
        boxes[i].display();
    }

    // Create a copy of the first box using the copy constructor
    Box b2 = boxes[0];  // Copy constructor called
    cout << "\nCopy of the first box:\n";
    b2.display();

    return 0;
}
