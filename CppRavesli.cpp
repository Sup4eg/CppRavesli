#include <iostream>
#include <string>
using namespace std;



class Lesson59 {
  //Explicit data type conversion
public:

  static float cStyleConversion(int i1, int i2) {
    //best not to use, doesn't check in compile time
    return (float) i1 / i2;
  }

  static float staticCastConversion(int i1, int i2) {
    //best to use, hase checking in compile 
    return static_cast<float>(i1) / i2;
  }
};

class Lesson60 {
  //Strings
public:
  
  static void pickAndEnterName() {
    cout << "Pick 1 or 2: ";
    int choice;
    cin >> choice;

    //ignore '\n' here
    cin.ignore(32767, '\n');

    cout << "Now enter your name: ";
    string myName;
    getline(cin, myName);

    cout << "Hello, " << myName << ", you picked " << choice << '\n';

  }

};





int main() {
  cout << Lesson59::cStyleConversion(11, 3) << endl;
  cout << Lesson59::staticCastConversion(11, 3) << endl;
  Lesson60::pickAndEnterName();
}