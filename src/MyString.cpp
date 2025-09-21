
//MyString.cpp
#include "MyString.h"

int MyString::staticVariable = 0;

MyString::~MyString()
{
	staticVariable--;
	//cout << "Destructor" << endl;
	delete[] string1;
	string1 = nullptr;
}
void MyString::setString1(const char* a)
{
	if (string1 != nullptr)
		delete[] string1;
	string1 = stringCopy(a);
}

void MyString::display()const
{
	if (string1 == nullptr)
		cout << "String is Empty" << endl;
	else
		cout << string1 << endl;
	// cout<<"Object ID : "<<ID<<endl;
}
void MyString::input()
{
	cout << "Enter any size of String" << endl;
	int size;
	cin >> size;
	char* a = new char[size];
	cout << "Enter string" << endl;
	cin.ignore();
	cin.getline(a, size);
	string1 = stringCopy(a);
	delete[] a;
	a = nullptr;
}
void MyString::append(const char* a)
{
	char* b = concatenation(string1, a);
	if (string1 == nullptr)
		string1 = stringCopy(b);
	else
	{
		delete[] string1;
		string1 = stringCopy(b);
	}
	delete[] b;
}
int MyString::compare(const char* a)
{
	int size1 = stringLength(a);
	int size2 = stringLength(string1);
	if (size1 > size2)
		return -1;
	else if (size2 > size1)
		return 1;
	else
		return 0; //When both strings Exactly Equal Length

}
bool MyString::isEmpty()
{
	if (string1 == nullptr)
		return 1;
	else
		return 0;
}
int stringLength(const char* a)
{
	int size = 0;
	if (a == nullptr)
		return 0;
	else
	{
		for (int i = 0; a[i] != '\0'; i++)
			size++;
	}
	return size;
}
char* stringCopy(const char* a)
{
	int size = stringLength(a);
	char* b;
	if (size == 0)
		return nullptr;
	else
	{
		b = new char[size + 1];
		for (int i = 0; i < size; i++)
			b[i] = a[i];
		b[size] = '\0';
	}
	return b;
}

char* concatenation(const char* a, const char* b)
{
	int size1 = stringLength(a);
	size1 = size1 + stringLength(b);
	char* c = new char[size1 + 1];
	int size = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		c[size] = a[i];
		size++;
	}
	for (int i = 0; b[i] != '\0'; i++)
	{
		c[size] = b[i];
		size++;
	}
	c[size1] = '\0';
	//cout << c << endl;
	return c;
}

void MyString::toUpperCase()
{
	if (!isEmpty())
	{
		for (int i = 0; string1[i] != '\0'; i++)
		{
			if (string1[i] >= 'a' && string1[i] <= 'z')
				string1[i] = string1[i] - 32;
		}
	}
}
// Appends a character to the end of string1.
void MyString::pushBack(char ch)
{
	int size = stringLength(string1) + 2;
	char* copyStr = new char[size];
	for (int i = 0; i < size - 2; i++)
	{
		copyStr[i] = string1[i];
	}
	copyStr[size - 2] = ch;
	delete[] string1;

	string1 = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		string1[i] = copyStr[i];
	}
	string1[size - 1] = '\0';
	delete[] copyStr;

}

// Removes the last character from string1
void MyString::popBack()
{
	if (isEmpty()) return;
	int size = stringLength(string1);
	char* copyStr = stringCopy(string1);

	delete[] string1;
	string1 = new char[size];

	for (int i = 0; i < size - 1; i++)
	{
		string1[i] = copyStr[i];
	}
	delete[] copyStr;
	string1[size - 1] = '\0';
}

void MyString::toLowerCase()
{
	if (!isEmpty())
	{
		for (int i = 0; string1[i] != '\0'; i++)
		{
			if (string1[i] >= 'A' && string1[i] <= 'Z')
				string1[i] = string1[i] + 32;
		}
	}
}

int MyString::findOccurrence(const char* a)
{
	int index = -1;
	if (isEmpty())
	{
		// cout << "Substring not found" << endl;
		return -1;
	}

	int size = stringLength(a);
	int size1 = stringLength(string1);
	for (int i = 0; string1[i] != '\0'; i++)
	{
		if (string1[i] == a[0])
		{
			index = i;
			int k = i;
			for (int j = 1; j < size; j++)
			{
				if ((i + 1 > size1) || a[j] != string1[k + 1])
				{
					index = -1;
					break;
				}
				k += 1;
			}
			if (index != -1)return index;
		}
	}
	//if(index==-1)	cout << "Substring not found" << endl;
	return index;
}

void MyString::insertString(const int& index, const char* a)
{
	if (index<0 || index>stringLength(string1))return;

	int size2 = stringLength(a);
	int size = stringLength(string1) + size2 + 1;
	char* string2 = new char[size];

	int j = 0;
	for (int i = 0; string1[i] != '\0'; i++)
	{
		if (i == index)
		{
			for (int k = 0; a[k] != '\0'; k++)
			{
				string2[j] = a[k];
				j++;
			}
		}

		string2[j] = string1[i];
		j++;

	}
	delete[] string1;
	j = 0;
	string1 = new char[size];
	for (int i = 0; string2[i] != '\0'; i++)
	{
		string1[i] = string2[j];
		j++;

	}
	string1[size - 1] = '\0';
	delete[] string2;
}



void MyString::erase(const char* a)
{
	int index = findOccurrence(a);
	if (index == -1)return;

	int size1 = stringLength(a);
	int size2 = stringLength(string1);
	size2 -= size1;

	char* copyStr = stringCopy(string1);
	delete[] string1;
	string1 = new char[size2 + 1];
	int j = 0;
	for (int i = 0; copyStr[i] != '\0'; i++)
	{
		if (!(i >= index && i < index + size1))
		{
			string1[j] = copyStr[i];
			j++;
		}
	}

	delete[] copyStr;
	string1[size2] = '\0';
}

char* MyString::stringSlicing(int start, int end)
{
	if (start<0 || end>stringLength(string1) || start >= end)
	{
		cout << "Invalid index" << endl;
		return nullptr;
	}
	int size = end - start;
	char* string2 = new char[size + 1];
	int index = 0;
	for (int i = start; i < end; i++)
	{
		string2[index] = string1[i];
		index++;
	}
	string2[size] = '\0';
	return string2;
}


MyString concatenationOfObject(const MyString& a, const MyString& b)
{
	MyString c;
	c.setString1(concatenation(a.getString1(), b.getString1()));
	return c;
}
bool isEqual(const MyString& a, const MyString& b)
{
	char* c = a.getString1();
	char* d = b.getString1();
	int size1 = stringLength(c);
	int size2 = stringLength(d);

	if (size1 == size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (c[i] != d[i])
			{
				return false;
			}

		}
	}
	else
	{

		return false;
	}

	return true;
}
MyString operator +(const MyString& a, const  MyString& b)
{
	return(concatenationOfObject(a, b));
}

MyString MyString::operator ++ ()
{
	int size = stringLength(string1);
	if (size == 0)
		return nullptr;
	char ch;
	for (int i = 0; i < size; i++)
	{
		ch = string1[i];
		string1[i] = ch + 1;
	}
	return *this;
}
MyString MyString::operator ++ (int)
{
	int size = stringLength(string1);
	if (size == 0)
		return nullptr;
	MyString one = *this;
	char ch;
	for (int i = 0; i < size; i++)
	{
		ch = string1[i];
		string1[i] = ch + 1;
	}
	return one;
}
MyString MyString::operator -- ()
{
	int size = stringLength(string1);
	if (size == 0)
		return nullptr;
	char ch;
	for (int i = 0; i < size; i++)
	{
		ch = string1[i];
		string1[i] = ch - 1;
	}
	return *this;
}
MyString MyString::operator -- (int)
{
	int size = stringLength(string1);
	if (size == 0)
		return nullptr;
	MyString one = *this;
	char ch;
	for (int i = 0; i < size; i++)
	{
		ch = string1[i];
		string1[i] = ch - 1;
	}
	return one;
}
bool operator == (const MyString& a, const MyString& b)
{
	int size1 = stringLength(a.getString1());
	int size2 = stringLength(b.getString1());
	return (size1 == size2);
}
bool operator != (const MyString& a, const MyString& b) { return !(a == b); }
bool MyString::operator <(const MyString& a)
{
	int size1 = stringLength(string1);
	int size2 = stringLength(a.getString1());
	return (size1 < size2);
}
bool MyString::operator <=(const MyString& a)
{
	int size1 = stringLength(string1);
	int size2 = stringLength(a.getString1());
	return (size1 <= size2);
}
bool MyString::operator >(const MyString& a)
{
	int size1 = stringLength(string1);
	int size2 = stringLength(a.getString1());
	return (size1 > size2);
}
bool MyString::operator >=(const MyString& a)
{
	int size1 = stringLength(string1);
	int size2 = stringLength(a.getString1());
	return (size1 >= size2);
}
MyString& MyString::operator =(const MyString& a)
{
	this->string1 = stringCopy(a.getString1());
	return *this;
}
void MyString::writing(ostream& out)
{
	if (string1 == nullptr)
		out << "nullptr" << endl;
	else
		out << string1;
	//out << ID;
}
ostream& operator <<(ostream& out, MyString& a)
{
	a.writing(out);
	return out;
}
istream& operator >>(istream& in, MyString& a)
{
	a.reading(in);
	return in;
}
void MyString::reading(istream& in)
{
	char name[20];
	//cin.ignore();
	cout << "Enter String" << endl;
	//cin.getline(name, 20);
	cin >> name;
	setString1(name);
}
ofstream& operator <<(ofstream& out, MyString& a)
{
	a.writingFile(out);
	return out;
}
void MyString::writingFile(ofstream& fout)
{
	fout << string1 << endl;
}
ifstream& operator >>(ifstream& in, MyString& a)
{
	a.readingFile(in);
	return in;
}
void MyString::readingFile(ifstream& fin)
{
	char name[200];
	//fin.getline(name, 200);
	fin >> name;
	setString1(name);
}
MyString* input(MyString* one, int& size)
{
	one = nullptr;
	cout << "Enter the number of Object of class" << endl;
	cin >> size;
	if (size == 0)
		return one;
	one = new MyString[size];
	for (int i = 0; i < size; i++)
	{
		cout << "String number=" << i + 1 << endl;
		cin >> one[i];
	}
	return one;
}
void display(MyString& a)
{
	cout << a << endl;
}
void trackNumberOfMyStringObjects()
{
	
	//This global function
	cout << "Current class object = " << MyString::objectCount() << endl;

}

MyString* readMyStringFromFile(MyString* a, int size, const char name[])
{

	ifstream fin;
	fin.open(name);
	a = new MyString[size];
	if (fin.is_open())
	{
		cout << "[INFO]  File found: " << name << endl;
		cout << "[READ]  Starting to read " << size << " strings..." << endl;
		
		for (int i = 0; i < size; i++)
		{
			fin >> a[i];
			cout << "   -> String #" << (i + 1) << ": " << a[i] << endl;
		}
		cout << "[DONE]  Finished reading file." << endl;
	}
	else
		cout << "[ERROR] File not found: " << name << endl;

	//cout << "File readindig has been finished" << endl;
	fin.close();
	return a;
}
void writeMyStringsToFile(MyString* a, int size, const char name[])
{
	ofstream fout;
	fout.open(name);
	cout << "File writing has been started " << name << endl;
	cout << "[INFO]  Writing " << size << " strings to file: " << name << endl;
	for (int i = 0; i < size; i++)
	{
		fout << a[i] << endl;
		cout << "   -> Wrote string #" << (i + 1) << ": " << a[i] << endl;
	}
	fout.close();
	cout << "[DONE]  File writing completed" << endl;
}
bool verifyMyStringsFiles(MyString* a, int size, const char name[])
{
	bool num = 1;
	MyString* two = nullptr;
	two = readMyStringFromFile(two, size, name);
	cout << "[INFO]  Verifying file content: " << name << endl;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == two[i]) {
			cout << "    Match: " << a[i] << " == " << two[i] << endl;
		}
		else {
			cout << "    Mismatch: " << a[i] << " != " << two[i] << endl;
			num = false;
		}
	}
	delete[] two;
	cout << "[DONE]  Verification: " << (num ? "Successful " : "Failed ") << endl;

	return num;
}
MyString testOperators(char a, MyString b, MyString c)
{
	MyString result;
	if (a == '+')
	{
		cout << "plus operation has been perform" << endl;

		result = b + c;
		cout << b << "+" << c << "=" << result << endl;
	}

	return result;
}
MyString testOperators(const char a[], const char b[], MyString c)
{
	MyString result;
	if (a[0] == '+')
	{
		if (b[1] == 'e')
		{
			cout << "Pre increment take place " << endl;
			cout << "Result of ++" << c << " \t-> ";
			++c;
			cout << c << endl;
			return c;
		}
		if (b[1] == 'o')
		{
			cout << "Post increment take place " << endl;
			cout << "Result of " << c << "++ \t-> ";
			result = c++;
			cout << result << endl;
			return result;
		}

	}
	if (a[0] == '-')
	{
		if (b[1] == 'e')
		{
			cout << "Pre decrement take place " << endl;
			cout << "Result of --" << c << " \t-> ";
			--c;
			cout << c << endl;
			return c;
		}
		if (b[1] == 'o')
		{
			cout << "Post increment take place " << endl;
			cout << "Result of " << c << "-- \t-> ";
			result = c--;
			cout << result << endl;
			return result;
		}

	}
	else
		cout << "invalid operator " << endl;
	return result;
}
MyString testOperators(char a, MyString b)
{
	MyString c;
	if (a == '=')
	{
		c = b;
		cout << "result of copy" << endl;
		cout << b << "=" << c << endl;
		return c;
	}
	else
		cout << "invalid operator" << endl;
	return c;
}
bool testOperatorsBool(const char a[], MyString b, MyString c)
{
	if (a[0] == '>' && a[1] == '\0')
	{
		cout << b << ">" << c << "     Result is " << (b > c) << endl;
		return (b > c);
	}
	if (a[0] == '>' && a[1] == '=')
	{
		cout << b << ">=" << c << "     Result is " << (b >= c) << endl;
		return (b >= c);
	}
	if (a[0] == '<' && a[1] == '\0')
	{
		cout << b << "<" << c << "     Result is " << (b < c) << endl;
		return (b < c);
	}
	if (a[0] == '<' && a[1] == '=')
	{
		cout << b << "<=" << c << "     Result is " << (b <= c) << endl;
		return (b <= c);
	}
	if (a[0] == '=' && a[1] == '=')
	{
		cout << b << "=" << c << "     Result is " << (b == c) << endl;
		return (b == c);
	}
	if (a[0] == '!' && a[1] == '=')
	{
		cout << b << "!=" << c << "     Result is " << (b != c) << endl;
		return (b != c);
	}
	cout << "invalid operator" << endl;
	return 0;
}