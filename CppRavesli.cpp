/**
 * @file CppRavesli.cpp
 *
 * @brief Cpp lesson from ravesli web site https://ravesli.com/uroki-cpp/
 *
 * @author @sup4eg
 *
 */


#include <iostream>
#include <string>
#include <string_view>
#include <cstddef>
#include <array>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <functional>
#include <cassert>
#include <cstdarg>
#include <initializer_list>
#include <cmath>

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

class Lesson84 {
  //Pointers
public:
  static void runPointers() {
	int a = 7;
	cout << a << endl;
	cout << &a << endl;
	cout << *&a << endl;

	int value = 5;
	int* ptr = &value;

	int x(4);
	cout << typeid(&x).name() << endl;

	char* chPtr;
	int* iPtr;

	struct Something {
	  int nX, nY, nZ;
	};

	Something* somethingPtr;

	cout << sizeof(chPtr) << endl; //4
	cout << sizeof(iPtr) << endl; //4
	cout << sizeof(somethingPtr) << endl; //4

  }
};

class Lesson85 {
  //nullptr lesson
public:
  static void checkNullPtrLogic(nullptr_t* ptr) {
	if (ptr) {
	  cout << "You passed in " << *ptr << endl;
	}
	else {
	  cout << "You passed in a null pointer" << endl;
	}
  }

};

class Lesson86 {
  //pointers and arrays
public:
  static void run() {

	int array[4] = { 5, 8, 6, 4 };

	cout << sizeof(array) << endl;

	int* ptr = array;

	cout << sizeof(ptr) << endl;

	cout << typeid(&array).name() << endl;
	cout << typeid(&ptr).name() << endl;

  }

};

class Lesson87 {
  //Address arithmetick
public:
  static void run() {
	int array[] = { 7, 8, 2, 4, 5 };
	cout << "Element 0 is at address: " << &array[0] << endl;
	cout << "Element 1 is at address: " << &array[1] << endl;
	cout << "Element 2 is at address: " << &array[2] << endl;
	cout << "Element 3 is at address: " << &array[3] << endl;

	cout << array[1] << endl;
	cout << *(array + 1) << endl;

	const int arrayLength = 9;
	char name[arrayLength] = "Jonathan";
	int numVowels = 0;
	for (char* ptr = name; ptr < name + arrayLength; ++ptr) {
	  switch (*ptr) {
	  case 'A':
	  case 'a':
	  case 'E':
	  case 'e':
	  case 'I':
	  case 'i':
	  case 'O':
	  case 'o':
	  case 'U':
	  case 'u':
		++numVowels;
	  }
	}
	cout << name << " has " << numVowels << " vowels.\n";
  }
};

class Lesson90 {
  //dynamic arrays
public:
  static void run() {

	int fixedArray[5] = { 9, 7, 5, 3, 1 };
	int* dynamicArray = new int[5] {9, 7, 5, 3, 1};

	delete[] dynamicArray;
	dynamicArray = nullptr;

	cout << "Enter a positive integer: ";
	int length;
	cin >> length;

	int* array = new int[length];
	cout << "I just allocated an array of integers of length " << length << '\n';

	array[0] = 7;
	delete[] array;
	array = 0;
  }
};

class Lesson91 {
public:
  static void run() {
	int value = 7;
	int& ref = value;

	value = 8;
	ref = 9;

	cout << value << endl;
	++ref;
	cout << value << endl;

	int value1 = 7;
	int value2 = 8;

	int& reference = value1;
	reference = value2;
	cout << value1 << endl;

	int x = 7;

	cout << x << endl;
	changeN(x);

	cout << x << endl;

  }

  static void changeN(int& ref) {
	ref = 8;
  }
};

class Lesson96 {
  //void ptr
public:
  static void run() {
	int nResult;
	float fResult;

	struct Something
	{
	  int n;
	  float f;
	};

	Something sResult;

	void* ptr;
	ptr = &nResult;
	ptr = &fResult;
	ptr = &sResult;

	int value = 7;
	void* voidPtr = &value;

	//cout << *voidPtr << endl; No, it is forbidden!!!

	int* intPtr = static_cast<int*>(voidPtr);
	//now
	cout << *intPtr << endl;

  }
};

class Lesson98 {
  //std::array
public:
  static void printLength(const array<double, 4>& myarray) {
	cout << "length: " << myarray.size() << endl;
  }
  static void run() {
	array<double, 4> myarray = { 8.0, 6.4, 4.3, 1.9 };
	printLength(myarray);
	sort(myarray.begin(), myarray.end());
	//sort(myarray.rbegin(), myarray.rend());

	for (const auto& element : myarray) {
	  cout << element << " ";
	}
	cout << endl;
  }
};

class Lesson99 {
  //std::vector
public:
  static void workWithVectors() {
	vector<int> array1 = { 12, 10, 8, 6, 4, 2, 1 };
	cout << "The length is: " << array1.size() << endl;

	vector<int> array2 = { 0, 1, 2 };
	array2.resize(7);

	cout << "The length is: " << array2.size() << endl;

	for (auto const& element : array2) {
	  cout << element << " ";
	}

  }
};

class Lesson100 {
  //Iterators
public:
  static void run() {

	//iterate using ptrs
	/*array data{0, 1, 2, 3, 4, 5, 6};
	auto begin = &data[0];
	auto end = begin + size(data);
	for (auto ptr = begin; ptr != end; ++ptr) {
	  cout << *ptr << " ";
	}
	cout << endl;
	*/

	//iterate using begin, end
	array arr = { 1, 2, 3 };
	auto begin = arr.begin();
	auto end = arr.end();

	for (auto p = begin; p != end; ++p) {
	  cout << *p << " ";
	}
	cout << endl;
  }
};

class Lesson101 {
  //Std Algorithms: find, find_if, count, count_if, sort, for_each
public:
  static void checkInput(int& search, int& replace) {
	while (1)
	{
	  if (cin.fail())
	  {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You have entered wrong input" << endl;
		cin >> search >> replace;
	  }
	  if (!cin.fail())
		break;
	}
  }
  static bool containsNut(string_view& str) {
	return (str.find("nut") != string_view::npos);
  }
  static bool greater(int a, int b) {
	return (a > b);
  }
  static void doubleNumber(int& i) {
	i *= 2;
  }

  static void runFind() {
	array<int, 6> arr{ 13, 90, 99, 5, 40, 80 };
	cout << "Enter a value to search for and replace with: ";
	int search = 0;
	int replace = 0;
	cin >> search >> replace;
	checkInput(search, replace);

	auto found = find(arr.begin(), arr.end(), search);

	if (found == arr.end()) {
	  cout << "Could not find " << search << endl;
	}
	else {
	  *found = replace;
	}

	for (auto const& i : arr) {
	  cout << i << " ";
	}
	cout << endl;
  }
  static void runFindIf() {
	array<string_view, 4> arr = { "apple", "banana", "walnut", "lemon" };
	auto found = find_if(arr.begin(), arr.end(), containsNut);

	if (found == arr.end()) {
	  cout << "No nuts\n";
	}
	else {
	  cout << "Found " << *found << endl;
	}
  }
  static void runCountIf() {
	array<string_view, 5> arr = { "apple", "banana", "walnut", "lemon", "peanut" };
	auto nuts = count_if(arr.begin(), arr.end(), containsNut);
	cout << "Counted: " << nuts << " nut(s)\n";
  }
  static void runSorting() {
	array<int, 6> arr = { 13, 90, 99, 5, 40, 80 };
	sort(arr.begin(), arr.end(), greater);

	for (auto const& i : arr) {
	  cout << i << " ";
	}
	cout << endl;
  }
  static void runForEach() {
	array<int, 4> arr = { 1, 2, 3, 4 };
	for_each(arr.begin(), arr.end(), doubleNumber);
	for (auto const& i : arr) {
	  cout << i << " ";
	}
	cout << endl;
  }

};

class Lesson105 {
  //Using ptr as parameter in a function
public:
  static void setToNull(int*& tempPtr) {
	tempPtr = nullptr;
  }

  static void runSetToNull() {
	int six = 6;
	int* ptr = &six;

	cout << *ptr;

	setToNull(ptr);

	if (ptr) {
	  cout << *ptr;
	}
	else {
	  cout << " ptr is null";
	}
  }
};

class Lesson110 {
  //Function ptr
public:
  static int boo(int a) {
	return 7;
  }
  static int doo(int b) {
	return 8;
  }
  static void runFuncPtrChecking() {
	int (*fcnPtr)(int) = boo;
	fcnPtr = doo;

	(*fcnPtr)(7);
	fcnPtr(10);
  }
  static bool ascending(int a, int b) {
	return a > b;
  }
  static bool descending(int a, int b) {
	return a < b;
  }
  static void printArray(int* array, int size) {
	for (int index = 0; index < size; ++index) {
	  cout << array[index] << " ";
	}
	cout << '\n';
  }
  static bool evensFirst(int a, int b) {
	if (!(a & 1) && (b & 1)) {
	  return false;
	}

	if ((a & 1) && !(b & 1)) {
	  return true;
	}

	return ascending(a, b);
  }
  static bool validate(int a, int b, function<bool(int, int)>  fcn) {
	return true;
  }
  static void selectionSort(int* array, int size, bool (*comparisonFunc)(int, int) = ascending) {
	for (int startIndex = 0; startIndex < size; ++startIndex) {
	  int smallestIndex = startIndex;
	  for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
		if (comparisonFunc(array[smallestIndex], array[currentIndex])) {
		  smallestIndex = currentIndex;
		}
	  }
	  swap(array[startIndex], array[smallestIndex]);
	}
  }
  static void runSelectionSort() {

	constexpr int ARRAY_LENGTH = 8;

	int array[ARRAY_LENGTH] = { 4, 8, 5, 6, 2, 3, 1, 7 };

	selectionSort(array, ARRAY_LENGTH, evensFirst);

	printArray(array, ARRAY_LENGTH);

	//selectionSort(array, ARRAY_LENGTH, ascending);
	//printArray(array, 8);
  }

};

class Lesson112 {
  //Vector capacity
public:
  static void printStack(const vector<int>& stack) {
	for (const auto& element : stack) {
	  cout << element << " ";
	}
	cout << "(cap " << stack.capacity() << " length " << stack.size() << " )\n";
  }
  static void run() {
	vector<int> array = { 0, 1, 2, 3 };
	array.resize(6);

	cout << "The length is: " << array.size() << endl;
	cout << "The capacity is: " << array.capacity() << endl;

	vector<int> array2 = { 0, 1, 2, 3, 4, 5 };
	cout << "length: " << array2.size() << " capacity: " << array2.capacity() << endl;

	array2 = { 8, 7, 6, 5 };
	cout << "length: " << array2.size() << " capacity: " << array2.capacity() << endl;

	for (auto const& el : array2) {
	  cout << el << " ";
	}
	cout << endl;

	vector<int> stack;

	stack.reserve(7);

	printStack(stack);
	stack.push_back(7); //add to stack
	printStack(stack);

	stack.push_back(4);
	printStack(stack);

	stack.push_back(1);
	printStack(stack);

	cout << "top: " << stack.back() << "\n";


	cout << "size of stack: " << sizeof(stack) << endl;

	stack.pop_back(); //delete first element on stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	cout << "size of stack: " << sizeof(stack) << endl << endl;

	vector<int> vect = { 0, 1, 2, 3, 4, 5 };
	cout << "size: " << vect.size() << " cap: " << vect.capacity() << endl;
	vect.push_back(6);
	cout << "size: " << vect.size() << " cap: " << vect.capacity() << endl;
  }

};

class Lesson113 {
  //Recursion
public:

  //Fibonacce
  static int fibonacce(int number) {
	if (number == 0 || number == 1) {
	  return number;
	}
	return fibonacce(number - 1) + fibonacce(number - 2);
  }

  //Factorial
  static int factorial(int number) {
	if (number == 1) {
	  return number;
	}
	return factorial(number - 1) * number;
  }

  //Sum numbers
  static int sumNumbers(int number) {
	if (!(number / 10)) {
	  return number;
	}
	return (number % 10) + sumNumbers(number / 10);
  }

  static void run() {
	cout << sumNumbers(83569) << endl;;
  }

};

class Lesson114 {
  //cerr, exit()
public:
  static int getArrayValue(const vector<int>& vect, int index) {
	if (index < 0 || index >= vect.size()) {
	  exit(2);
	}
	return vect.at(index);
  }

  static int getArrayValueWithAssert(const array<int, 10>& array, int index) {
	assert(index >= 0 && index <= 8);
	return array[index];
  }

  static void printString(const char* cstring) {
	if (cstring) {
	  cout << cstring;
	}
	else {
	  cerr << "function printString() received a null parameter";
	}
  }
};

class Lesson117 {
  //Ellipsis
public:
  static double findAverage(int count, ...) {
	double sum = 0;

	//Ellipsis access
	va_list list;

	//count - last parameter which is not ellipsis
	va_start(list, count);

	for (int arg = 0; arg < count; ++arg) {
	  //use va_arg to get parameters from ellipsis
	  sum += va_arg(list, int);
	}
	va_end(list);
	return sum / count;
  }
};

class Lesson118 {
  //lambda
public:

  static void repeat(int repetitions, const function<void(int)>& fn) {
	for (int i = 0; i < repetitions; ++i) {
	  fn(i);
	}
  }

  static void run() {
	array<string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
	auto found{ find_if(arr.begin(), arr.end(), [](string_view str) {return (str.find("nut") != string_view::npos); }) };
	if (found == arr.end()) {
	  cout << "No nuts\n";
	}
	else {
	  cout << "Found " << *found << endl;
	}

	double (*addNumbers1)(double, double) = [](double a, double b) { return (a + b); };
	cout << addNumbers1(1, 2) << endl;

	function addNumbers2 = [](double a, double b) { return (a + b); };
	cout << addNumbers2(3, 4) << endl;

	auto addNumbers3 = [](double a, double b) { return (a + b); };
	cout << addNumbers3(5, 6) << endl;

	repeat(3, [](int i) {cout << i << "\n"; });
  }
};

class Lesson119 {
  //Lambda capture clause
public:

  struct Car {
	string make{};
	string model{};
  };

  static void run() {
	array arr = { "apple", "banana", "walnut", "lemon" };
	cout << "search for: ";
	string search = "";
	cin >> search;


	auto found = find_if(arr.begin(), arr.end(), [search](string_view str) {return (str.find(search) != string_view::npos); });

	if (found == arr.end()) {
	  cout << "Not found\n";
	}
	else {
	  cout << "Found " << *found << endl;
	}

	int ammo = 10;
	auto shoot = [&ammo]() mutable {
	  --ammo;
	  cout << "Pew! " << ammo << " shot(s) left.\n";
	  };

	shoot();
	shoot();

	cout << ammo << " shot(s) left\n";
  }

  static void sortCars() {
	array<Car, 3> cars{ { {"Volkswaggen", "Golf"}, {"Toyota", "Corolla"}, {"Honda", "Civic"} } };
	int comparisons = 0;

	sort(cars.begin(), cars.end(), [&comparisons](const auto& a, const auto& b) {
	  ++comparisons;
	  return (a.make < b.make);
	  });

	for (const auto& car : cars) {
	  cout << car.make << " " << car.model << endl;
	}
  }

  static void invoke(const function<void(void)>& fn) {
	fn();
  }

  static void checkLambdaCopies() {
	int i = 0;
	auto count = [i]() mutable { cout << ++i << endl; };

	auto otherCount = ref(count);

	count();
	otherCount();

	//2
	invoke(ref(count));
	//2
	invoke(ref(count));
	//2
	invoke(ref(count));

  }
};

class Lesson125 {
  //Class list initialization
public:
  class Values {
  private:
	int m_value1;
	double m_value2;
	char m_value3;
  public:
	Values(int value1, double value2, char value3 = 'd') : m_value1(value1), m_value2(value2), m_value3(value3) {}

	void print() {
	  cout << "Values(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
	}
  };
};

class Lesson128 {
  //Destructor
public:
  class Massiv
  {
  private:
	int* m_array;
	int m_length;
  public:
	Massiv(int length) {
	  assert(length > 0);
	  m_array = new int[length];
	  m_length = length;
	}

	//Destructor
	~Massiv() {
	  cout << "Run destructor here" << endl;
	  delete[] m_array;
	  m_array = nullptr;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }
	int getLength() { return m_length; };
  };

};

class Lesson129 {
  //this lesson
public:
  class Mathem {
  private:
	int m_value;
  public:
	Mathem() : m_value(0) {}

	Mathem& add(int value)
	{
	  m_value += value;
	  return *this;
	}

	Mathem& sub(int value) {
	  m_value -= value;
	  return *this;
	}

	Mathem& multiply(int value) {
	  m_value *= value;
	  return *this;
	}

	int getValue() {
	  return m_value;
	}

  };
};

class Lesson134 {
  //friend functions and classes

public:
  class Anything {
  private:
	int m_value;
  public:
	Anything() {
	  m_value = 0;
	}
	void add(int value) { m_value += value; }

	//friend function
	friend void reset(Anything& Anything);
  };
};

class Lesson139 {
public:
  class Dollars {
  private:
	int m_dollars;
  public:
	Dollars(int dollars) {
	  m_dollars = dollars;
	}

	//Dollars + int
	friend Dollars operator+(const Dollars& d1, int value);

	//int + Dollars
	friend Dollars operator+(int value, const Dollars& d1);

	int getDollars() {
	  return m_dollars;
	}
  };
};

class Lesson145 {

public:
  class Number {

  private:
	int m_number;
  public:
	Number(int number = 0) : m_number(number) {}

	Number& operator++();
	Number& operator--();
	Number operator++(int);
	Number operator--(int);

	friend ostream& operator<<(ostream& out, const Number& n);
  };

};

Lesson145::Number& Lesson145::Number::operator++() {
  if (m_number == 0) {
	m_number = 0;
  }
  else {
	++m_number;
  }
  return *this;
}

Lesson145::Number& Lesson145::Number::operator--() {
  if (m_number == 0) {
	m_number = 0;
  }
  else {
	--m_number;
  }
  return *this;
}

Lesson145::Number Lesson145::Number::operator++(int) {
  Number temp(m_number);
  ++(*this);
  return temp;
}

Lesson145::Number Lesson145::Number::operator--(int) {
  Number temp(m_number);
  --(*this);
  return temp;
}

ostream& operator<<(ostream& out, const Lesson145::Number& n) {
  out << n.m_number;
  return out;
}


class Values;

//for lesson 134
class Display {
private:
  bool m_displayIntFirst;
public:
  Display(bool displayIntFirst) {
	m_displayIntFirst = displayIntFirst;
  }
  void displayItem(Values& value);
};

//for lesson 134
class Values {
private:
  int m_intValue;
  double m_dValue;
public:

  Values(int intValue, double dValue) {
	m_intValue = intValue;
	m_dValue = dValue;
  }

  //friend class Display for class Values
  friend void Display::displayItem(Values& value);
};

void reset(Lesson134::Anything& anything) {
  anything.m_value = 0;
}

//for lesson 139
Lesson139::Dollars operator+(const Lesson139::Dollars& d1, int value)
{
  return Lesson139::Dollars(d1.m_dollars + value);
}

Lesson139::Dollars operator+(int value, const Lesson139::Dollars& d1)
{
  return Lesson139::Dollars(d1.m_dollars + value);
}

void Display::displayItem(Values& value) {
  if (m_displayIntFirst) {
	cout << value.m_intValue << " " << value.m_dValue << "\n";
  }
  else {
	cout << value.m_dValue << " " << value.m_intValue << "\n";
  }
}


class Lesson146 {
public:
  class IntArray {
  private:
	int m_array[10];
  public:
	int& operator[] (const int index) {
	  assert(index >= 0 && index < 10);
	  return m_array[index];
	}
	const int& operator[] (const int index) const {
	  assert(index >= 0 && index < 10);
	  return m_array[index];
	}
  };

};

class Lesson149 {
public:
  class Drob {
  private:
	int m_numerator;
	int m_denominator;
  public:
	//default constructor
	Drob(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
	  assert(denominator != 0);
	}

	Drob(const Drob& drob) : m_numerator(drob.m_numerator), m_denominator(drob.m_denominator) {
	  cout << "Copy constructor worked here" << endl;
	}

	friend ostream& operator<<(ostream& out, const Drob& d1) {
	  out << d1.m_numerator << "/" << d1.m_denominator;
	  return out;
	}
  };
};

class Lesson151 {
public:
  class SomeString {
  private:
	string m_string;
  public:
	SomeString(char) = delete; //usage of this statement is error

	explicit SomeString(int a) {
	  m_string.resize(a);
	}

	SomeString(const char* string) {
	  m_string = string;
	}

	friend ostream& operator<<(ostream& out, const SomeString& s) {
	  out << s.m_string;
	  return out;
	}
  };
};

class Lesson152 {
public:
  class Drob {
  private:
	int m_numerator;
	int m_denominator;

  public:
	Drob(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
	  assert(denominator != 0);
	}

	Drob(const Drob& drob) = delete;
	Drob& operator=(const Drob& drob) = delete;

	friend ostream& operator<<(ostream& out, const Drob& d1) {
	  out << d1.m_numerator << "/" << d1.m_denominator;
	  return out;
	}
  };
};

class Lesson160 {
public:
  class ArrayInt {
  private:
	int m_length;
	int* m_data;

  public:
	ArrayInt() : m_length(0), m_data(nullptr) {}
	ArrayInt(int length) : m_length(length) {
	  m_data = new int[length];
	}
	ArrayInt(const initializer_list<int>& list) : ArrayInt((int)list.size()) {
	  int count = 0;
	  for (auto& element : list) {
		m_data[count] = element;
		++count;
	  }
	}
	~ArrayInt() {
	  delete[] m_data;
	}

	int& operator[](int index) {
	  assert(index >= 0 && index < m_length);
	  return m_data[index];
	}

	int getLength() {
	  return m_length;
	}
  };
};

class Lesson164 {
public:
  class Parent {
  private:
	int m_id;
  public:
	Parent(int id = 0) : m_id(id) {
	}
	int getId() const { return m_id; }
  };

  class Child : public Parent
  {
  private:
	double m_value;
  public:
	Child(double value = 0.0, int id = 0) : Parent(id), m_value(value) {}
	double getValue() const { return m_value; }
  };
};

class Lesson168 {
public:
  class Parent {
  private:
	int m_value;
  public:
	Parent(int value) : m_value(value) {}

  protected:
	void printValue() {
	  cout << m_value;
	}
  };

  class Child : public Parent {

  public:
	Child(int value) : Parent(value) {};
	using Parent::printValue;
  };
};

class Lesson170 {
public:
  class Parent {
  protected:
	int m_value;
  public:
	Parent(int value) : m_value(value) {}
	const char* getName() const { return "Parent"; }
	int getValue() const { return m_value; }
  };

  class Child : public Parent {
  public:
	Child(int value) : Parent(value) {}
	const char* getName() const { return "Child"; }
	int getValueDoubled() const { return m_value * 2; }
  };
};

class Lesson171 {
public:
  class Parent {
  public:
	virtual const char* getName() const { return "Parent"; }
  };

  class Child : public Parent {
  public:
	virtual const char* getName() const { return "Child"; }
  };
};

class Lesson172 {
public:
  class Parent {
  public:
	virtual Parent* getThis() {
	  cout << "Called Parent::getThis()\n";
	  return this;
	}

	void printType() {
	  cout << "returned a Parent\n";
	}
  };

  class Child : public Parent {
  public:
	virtual Child* getThis() override {
	  cout << "called Child::getThis()\n";
	  return this;
	}
	void printType() {
	  cout << "returned a Child\n";
	}
  };
};

class Lesson173 {
public:
  class Parent {
  public:
	virtual ~Parent() {
	  cout << "Calling ~Parent()" << endl;
	}
  };

  class Child : public Parent {
  private:
	int* m_array;
  public:
	Child(int length) {
	  m_array = new int[length];
	}

	virtual ~Child() {
	  cout << "Calling ~Child()" << endl;
	  delete[] m_array;
	}
  };
};

class Lesson177 {
public:
  class PoweredDevice {
  public:
	PoweredDevice(int power) {
	  cout << "Powered device: " << power << endl;
	}
  };

  class Scanner : virtual public PoweredDevice {
  public:
	Scanner(int scanner, int power) : PoweredDevice(power) {
	  cout << "Scanner: " << scanner << endl;
	}
  };

  class Printer : virtual public PoweredDevice {
  public:
	Printer(int printer, int power) : PoweredDevice(power){
	  cout << "Printer: " << printer << endl;
	}
  };

  class Copier : public Scanner, public Printer {
  public:
	Copier(int scanner, int printer, int power) : Scanner(scanner, power), Printer(printer, power), PoweredDevice(power) {}
  };

};

class Lesson180 {
public:
  class Parent {
  
  public:
	
	Parent() {}

	friend ostream& operator<<(ostream& out, const Parent& p) {
	  return p.print(out);
	}

	virtual ostream& print(ostream& out) const { 
	  out << "Parent"; 
	  return out;
	}
  };

  class Child : public Parent {
  public:
	Child() {}
	virtual ostream& print(ostream& out) const override { 
	  out << "Child"; 
	  return out;
	}
  };

};

class Lesson181 {
public:
  template <typename T>
  static const T& max(const T& a, const T& b) {
	return (a > b) ? a : b;
  }
};

class Lesson184 {
public:
  template <class T, int size>
  class StaticArray {
  private:
	T mArray[size];
  public:
	T* getArray();

	T& operator[] (int index){
	  return mArray[index];
	}
  };

};

template <class T, int size>
T* Lesson184::StaticArray<T, size>::getArray() {
  return mArray;
}

class Lesson186 {
public:
  template <class T>
  class Repository8 {
  private:
	T mArray[8];
  public:
	void set(int index, const T& value) {
	  mArray[index] = value;
	}

	const T& get(int index) {
	  return mArray[index];
	}
  };

  template<>
  class Repository8<bool> {
  private:
	unsigned char mData;
  public:
	Repository8() : mData(0) {
	}

	void set(int index, bool value) {
	  if (value) {
		mData |= 1 << index;
	  }
	  else {
		mData &= ~(1 << index);
	  }
	}

	bool get(int index) {
	  return (mData & 1 << index) != 0;
	}
  };
};

class Lesson187 {

public:
  template <class T, int size>
  class StaticArrayBase {
  protected:
	T mArray[size] {};

  public:

	T* getArray() { return mArray; }
	
	T& operator[](int index) {
	  return mArray[index];
	}

	virtual void print() {
	  for (int i = 0; i < size; ++i) {
		cout << mArray[i] << " ";
	  }
	  cout << endl;
	}
  };

  template <class T, int size>
  class StaticArray : public StaticArrayBase<T, size> {};

  template <int size>
  class StaticArray <double, size> : public StaticArrayBase<double, size>
  {
  public:
	virtual void print() override {
	  for (int i = 0; i < size; ++i) {
		cout << scientific << this->mArray[i] << " ";
	  }
	  cout << endl;
	}
  };

};

class Lesson192 {
public:
  static double mySqrt(double a) {
	if (a < 0.0) {
	  throw "Can not take sqrt to negative number";
	}
	return sqrt(a);
  }
};

class Lesson193 {
public:
  class ArrayException : public exception {
  private:
	string mError;
  public:
	ArrayException(string error) : mError(error) {}
	virtual const char* what() const noexcept override {
	  return mError.c_str();
	}
  };

  class ArrayInt {
  private:
	int mData[4]{ 0 };
  public:
	int getLength() { return 4; }

	int& operator[](const int index) {
	  if (index < 0 || index >= getLength()) {
		throw ArrayException("Invalid index");
	  }
	  return mData[index];
	}
  };

  class Parent {
  public:
	Parent() {}
  };

  class Child : public Parent {
  public:
	Child() {}
  };
};

class Lesson195 {
public:
  class A {
  private:
	int mX;
  public:
	A(int x) : mX(x) {
	  if (x <= 0) {
		throw 1;
	  }
	}
  };

  class B : public A {
  public:
	B(int x) try : A(x) {
	  
	}
	catch (...) {
	  cerr << "Construction of A failed\n" << endl;
	}
  };
};


int main() {

  try
  {
	Lesson195::B b(0);
  }
  catch (int)
  {
	cout << "Oooops!" << endl;
  }
  return 0;

}