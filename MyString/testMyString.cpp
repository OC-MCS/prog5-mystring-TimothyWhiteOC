// Timothy White - Assignment 5 - MyString
// Copy constructor and destructor both appear to be called a number of times
// I think all of these are in situations where it is necessary (primarily returning from functions)
#include <iostream>
#include "MyString.h"
using namespace std;

void displayFunc(MyString);
MyString returnFunc(MyString);

int main() {
	MyString s1;
	MyString s2("test");
	MyString s3(s2);

	cout << "Initialization:" << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl << endl;

	s1 = s2 = s3;
	cout << "s1 = s2 = s3:" << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl << endl;

	s1 = s2 + " " + s3;
	cout << "s1 = s2 + \" \" + s3:" << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl << endl;

	MyString isEqual;
	if (s1 == s2) { isEqual = "TRUE"; }
	else { isEqual = "FALSE"; }
	cout << "s1 == s2: " << isEqual << endl << endl;

	if (s2 == s3) { isEqual = "TRUE"; }
	else { isEqual = "FALSE"; }
	cout << "s2 == s3: " << isEqual << endl << endl;

	cout << "Passing s1 to displayFunc():" << endl;
	displayFunc(s1);
	cout << endl;

	cout << "Passing s1 to returnFunc(): " << returnFunc(s1) << endl << endl;

	s1 = s1;
	cout << "s1 = s1:" << endl;
	cout << "s1: " << s1 << endl;
}


// displayFunc(): simply couts the value of a MyString
void displayFunc(MyString s) {
	cout << "Inside displayFunc(): " << s << endl;
}

// returnFunc(): simply returns a copy of a MyString
MyString returnFunc(MyString s) {
	MyString s2 = s;
	return s2;
}