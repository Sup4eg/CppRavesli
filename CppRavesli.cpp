#include <iostream>
#include <string>
#include <string_view>

using namespace std;



class Lesson59 {
  //Explicit data type conversion
public:

  static float cStyleConversion(int i1, int i2) {
	//best not to use, doesn't check in compile time
	return (float)i1 / i2;
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
	}
	else if (color == Colors::GRAY) {
	  cout << "The color is gray" << endl;
	}

	//explisit conversion
	cout << static_cast<int>(color);

  }

};

class Lesson64 {
  //Structs

public:

  struct Employee {
	short id;
	int age;
	double salary;
  };

  struct Triangle {
	double length = 2.0;
	double width = 2.0;
  };

  static void createEmployeeInDiffMethods() {
	Employee john = { 5, 27, 45000.0 };
	Employee james = { 6, 29 }; //salary = 0.0

	//uniform initialization
	//Employee john { 5, 27, 45000.0 };
	//Employee james{ 6, 29 }; //salary = 0.0
  }

};

class Lesson82 {
//C-style strings
public:
  static void useCStyleStrings() {
	char mystring[] = "string";
	cout << mystring << " has " << sizeof(mystring) << " characters.\n";
	for (int index = 0; index < sizeof(mystring); ++index) {
	  cout << static_cast<int>(mystring[index]) << " ";
	}
	cout << endl;

	char name[10];
	cout << "Enter your name: ";
	//cin >> name;
	cin.getline(name, 10);
	cout << "You entered: " << name << endl;
  }

};

class Lesson83 {
  //string_view lesso
public:
  static void useStringView() {
	char text[]{ "Peach" };

	string_view str{ text };

	cout << str << endl;

	//remove first symbol
	str.remove_prefix(1);

	cout << str << endl;

	//remove last 2 symbols
	str.remove_suffix(2);

	cout << str << endl;
	
  }
};

int main() {
  Lesson82::useCStyleStrings();
}