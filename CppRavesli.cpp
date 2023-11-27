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


class Lesson62 {
  //Enum classess

private:
  enum class Fruits
  {
    LEMON,
    KIWI
  };

  enum class Colors 
  {
    PINK,
    GRAY
  };

public:
  static void checkEnumClassesNotEqual() {
    Fruits fruit = Fruits::LEMON;
    Colors color = Colors::PINK;

    //Not working, because different classes;
    /*if (fruit == color) {
      
    }*/

    //awailable
    if (color == Colors::PINK) {
      cout << "The color is pink" << endl;
    } else if (color == Colors::GRAY) {
      cout << "The color is gray" << endl;
    }

    //explisit conversion
    cout << static_cast<int>(color);

  }

};





int main() {
  Lesson62::checkEnumClassesNotEqual();
}