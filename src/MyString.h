
//MyString.h
#pragma Once
#include<iostream>
#include<fstream>
using namespace std;

int stringLength(const char* a);
char* stringCopy(const char* a);
char* concatenation(const char* a, const char* b);


class MyString
{
public:

	//Default constructor, initializes string1 to nullptr
	MyString() { string1 = nullptr; }

	//Constructor, deep - copies a
	MyString(const char* a) { string1 = stringCopy(a); }

	//Copy constructor, deep-copies another MyString
	MyString(const MyString& a) { string1 = stringCopy(a.string1); }

	//Destructor, releases allocated memory and decrements counter.
	~MyString();

	

	//Replaces current string with a deep copy of a
	void setString1(const char* a);

	//Returns object’s ID.
	int getID()const { return ID; }

	//Returns a copy of the internal string
	char* getString1()const { return stringCopy(string1); }

	//Prints string (or empty if nullptr).
	void display()const;

	//Reads string from user.
	void input();

	//Concatenates another string to the end.
	void append(const char* a);

	// Returns the length of the stored string (`string1`).
	int count()const { return stringLength(string1); }

	// Replaces the current string with a copy of the given C-string `a`.
	void copy(const char* a) { setString1(a); }

	//Compares lengths of two strings.
	int compare(const char* a);

	//Checks if string1 is empty or not.
	bool isEmpty();

	//Returns substring
	char* stringSlicing(int start, int end);

	// Finds first occurrence index of substring `a` inside `string1`
	int findOccurrence(const char* a);

	// Converts the contents of `string1` to uppercase letters in place.
	void toUpperCase();

	// Converts the contents of `string1` to lowercase letters in place.
	void toLowerCase();
	
	// Returns the first character of `string1`, or '\0' if empty.
	char front(){ return !isEmpty() ? string1[0] : '\0'; }
	
	// Returns the Last character of `string1`, or '\0' if empty.
	char back() { return !isEmpty() ? string1[stringLength(string1) - 1] : '\0'; }

	// → Add / remove last character.
	// Appends a character to the end of string1.
	void pushBack(char ch);

	// Removes the last character from string1
	void popBack();

	// Removes the first occurrence of substring from string1.
	void erase(const char* a);
	

	// Inserts the substring `substr` into string1 at the given index.
	void insertString(const int& index, const char* a);
	
			
		 
	//increment  Or Decrement operator
	MyString operator ++ ();
	MyString operator ++ (int);
	MyString operator -- ();
	MyString operator -- (int);
	
	//Boolian operator
	//Noted that This comparison Take place on String Lenght not on string Character
	bool operator <(const MyString& one);
	bool operator <=(const MyString& a);
	bool operator >(const MyString& a);
	bool operator >=(const MyString& a);

	//Assignment opeartor =
	MyString& operator =(const MyString& a);

	static int objectCount() { return staticVariable; }

	void writing(ostream& out);
	void reading(istream& in);
	void writingFile(ofstream& fout);
	void readingFile(ifstream& fin);

	static int staticVariable;
	const int ID = ++staticVariable;

private:
	char* string1;

};

MyString operator +(const MyString& a, const  MyString& b);
MyString concatenationOfObject(const MyString& a, const  MyString& b);
bool isEqual(const MyString& a, const MyString& b);
bool operator == (const MyString& a, const MyString& b);
bool operator != (const MyString& a, const MyString& b);
ostream& operator <<(ostream& out, MyString& a);
istream& operator >>(istream& in, MyString& a);
ofstream& operator <<(ofstream& out, MyString& a);
ifstream& operator >>(ifstream& in, MyString& a);
MyString* input(MyString*, int& size);
void display(MyString& a);
void trackNumberOfMyStringObjects();
MyString* readMyStringFromFile(MyString* a, int size, const char name[]);
void writeMyStringsToFile(MyString* a, int size, const char name[]);
bool verifyMyStringsFiles(MyString* a, int size, const char name[]);
MyString testOperators(char a, MyString b, MyString c);
MyString testOperators(const char a[], const char b[], MyString c);
MyString testOperators(char a, MyString b);
bool testOperatorsBool(const char a[], MyString b, MyString c);