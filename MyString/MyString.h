#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char *str;
	void copy(const MyString&);
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString operator=(const MyString&);
	MyString operator+(MyString);
	bool operator==(MyString);
	char* c_str() const;
	~MyString();
};

// Including a prototype for overloaded output in the header file so main knows it exists
ostream& operator<<(ostream& o, const MyString& s);