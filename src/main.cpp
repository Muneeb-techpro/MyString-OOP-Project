
//main.ccp
#include<iostream>
#include<fstream>
#include "MyString.h"
using namespace std;


int main() {
    cout << "================= Testing MyString Class =================" << endl;

    // 1. Default constructor
    cout << "\n[1] Testing default constructor:" << endl;
    MyString s1;
    s1.display();
    trackNumberOfMyStringObjects();

    // 2. Parameterized constructor
    cout << "\n[2] Testing parameterized constructor:" << endl;
    MyString s2("Hello");
    s2.display();
    trackNumberOfMyStringObjects();

    // 3. Copy constructor
    cout << "\n[3] Testing copy constructor:" << endl;
    MyString s3(s2);
    s3.display();
    trackNumberOfMyStringObjects();

    // 4. Assignment operator
    cout << "\n[4] Testing assignment operator:" << endl;
    MyString s4;
    s4 = s2;
    s4.display();

    // 5. Append
    cout << "\n[5] Testing append function:" << endl;
    s2.append(" World!");
    cout << "After append: ";
    s2.display();

    // 6. Copy
    cout << "\n[6] Testing copy():" << endl;
    s1.copy("New String");
    cout << "s1 copied as: ";
    s1.display();

    // 7. Compare
    cout << "\n[7] Testing compare():" << endl;
    cout << "Compare 'Hello' with s2: " << endl;
    (s2.compare("Hello") == 0) ? cout << "Equal" << endl : cout << "Not Equal" << endl;
    cout << "Compare 'Hello Wold!' with s2: " << endl;
    (s2.compare("Hello Wrold!") == 0) ? cout << "Equal" << endl : cout << "Not Equal" << endl;

    // 8. isEmpty()
    cout << "\n[8] Testing isEmpty():" << endl;
    MyString s5;
    cout << "s5 empty? " << s5.isEmpty() << endl;
    cout << "s3 empty? " << s3.isEmpty() << endl;

    // 9. pushBack() / popBack()
    cout << "\n[9] Testing pushBack & popBack:" << endl;
    s3.pushBack('!');
    cout << "After pushBack: ";
    s3.display();
    s3.popBack();
    cout << "After popBack: ";
    s3.display();

    // 10. Erase
    cout << "\n[10] Testing erase():" << endl;
    s2.erase("World");
    cout << "After erasing 'World': ";
    s2.display();

    // 11. Insert string
    cout << "\n[11] Testing insertString():" << endl;
    s2.insertString(5, " C++");
    cout << "After insertion: ";
    s2.display();

    // 12. String slicing
    cout << "\n[12] Testing stringSlicing():" << endl;
    char* sliced = s2.stringSlicing(0, 5);
    cout << "Sliced: " << sliced << endl;
    delete[] sliced;

    // 13. findOccurrence()
    cout << "\n[13] Testing findOccurrence():" << endl;
    cout << "Index of 'C++' in s2: " << s2.findOccurrence("C++") << endl;

    // 14. toUpperCase / toLowerCase
    cout << "\n[14] Testing case conversions:" << endl;
    s2.toUpperCase();
    cout << "UpperCase: "; s2.display();
    s2.toLowerCase();
    cout << "LowerCase: "; s2.display();

    // 15. front() & back()
    cout << "\n[15] Testing front & back:" << endl;
    cout << "Front: " << s2.front() <<endl;
    cout << "Back: " << s2.back() << endl;

    // 16. Operator overloading (++ / --)
    cout << "\n[16] Testing ++ and -- operators:" << endl;
    MyString s6("ABC");
    cout << "Original: "; s6.display();

    // Post-increment: return old value, then increment
    MyString postResult = s6++;
    cout << "After post-increment (s6++):" << endl;
    cout << "   s6 (after increment): "; s6.display();
    cout << "   postResult (old value): "; postResult.display();

    // Pre-increment: increment first, then return new value
    MyString preResult = ++s6;
    cout << "After pre-increment (++s6):" << endl;
    cout << "   s6 (after increment): "; s6.display();
    cout << "   preResult (new value): "; preResult.display();

    // Post-decrement
    MyString postDec = s6--;
    cout << "After post-decrement (s6--):" << endl;
    cout << "   s6 (after decrement): "; s6.display();
    cout << "   postDec (old value): "; postDec.display();

    // Pre-decrement
    MyString preDec = --s6;
    cout << "After pre-decrement (--s6):" << endl;
    cout << "   s6 (after decrement): "; s6.display();
    cout << "   preDec (new value): "; preDec.display();


    // 17. Operator + (concatenation)
    cout << "\n[17] Testing + operator:" << endl;
    MyString s7("First");
    MyString s8("Second");
    MyString s9 = s7 + s8;
    cout << "s7 + s8 = ";
    s9.display();

    // 18. Comparison operators
    cout << "\n[18] Testing comparison operators:" << endl;
    cout << (s7 < s8 ? "s7 < s8" : "s7 >= s8") << endl;
    cout << (s7 == s8 ? "s7 == s8" : "s7 != s8") << endl;

    // 19. File Writing
    cout << "\n[19] Testing file writing:" << endl;
    MyString arr[3] = { MyString("One"), MyString("Two"), MyString("Three") };
    writeMyStringsToFile(arr, 3, "output.txt");

    // 20. File Reading
    cout << "\n[20] Testing file reading:" << endl;
    MyString* arr2 = nullptr;
    int size = 3;
    arr2 = readMyStringFromFile(arr2, size, "output.txt");
    for (int i = 0; i < size; i++) {
        cout << "Read[" << i << "]: " << arr2[i] << endl;
    }
    delete[] arr2;

    // 21. Verify File
    cout << "\n[21] Testing file verification:" << endl;
    bool verified = verifyMyStringsFiles(arr, 3, "output.txt");
    cout << "Verification result: " << (verified ? "Match" : "Mismatch") << endl;

    // 22. Operator testing helper functions
    //Note: "pe" stand for "pre-operation", "po" stand for "post-operation".
    cout << "\n[22] Testing operator helper functions:" << endl;
   testOperators("+", "pe", s6); // instead of "ro"
    testOperators("+", "po", s6);
    testOperators("-", "pe", s6);
    testOperators("-", "po", s6);

    cout << "\n================= Program Finished =================" << endl;
    return 0;
}



