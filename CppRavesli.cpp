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
  static void checkInput(int &search, int &replace) {
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
  static void printStack(const vector<int> &stack) {
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

int main() {
  Lesson112::run();
}