#include <cstring>
#include <iostream>
#include "MyString.h"
using namespace std;

// Default constructor
MyString::MyString() {
	str = new char;
	strcpy_s(str, 1, "");
}

// Constructor that accepts c-string
MyString::MyString(const char* input) {
	int size = strlen(input) + 1;
	str = new char[size];
	strcpy_s(str, size, input);
}

// Copy constructor
MyString::MyString(const MyString& other) {
	cout << "Inside copy constructor, copying " << other.str << endl;
	copy(other);
}

// Overloaded assignment
MyString MyString::operator=(const MyString& other) {
	if (this != &other) {
		delete[] str;
		copy(other);
	}
	return *this;
}

// Overloaded addition
MyString MyString::operator+(MyString other) {
	MyString sum;
	int size = strlen(str) + strlen(other.str) + 1;
	sum.str = new char[size];
	strcpy_s(sum.str, size, str);
	strcat_s(sum.str, size, other.str);
	return sum;
}

// Overloaded comparison
bool MyString::operator==(MyString other) {
	return strcmp(str, other.str) == 0;
}

// c_str(): returns the pointer to the internal c-string
char* MyString::c_str() const {
	return str;
}

// copy(): private function to copy data from another MyString, used in copy constructor and overloaded assignment
void MyString::copy(const MyString& other) {
	int size = strlen(other.str) + 1;
	str = new char[size];
	strcpy_s(str, size, other.str);
}

// Destructor
MyString::~MyString() {
	cout << "Inside destructor, deleting " << str << endl;
	delete[] str;
}

// Overloaded output
ostream& operator<<(ostream& o, const MyString& s) {
	o << s.c_str();
	return o;
}