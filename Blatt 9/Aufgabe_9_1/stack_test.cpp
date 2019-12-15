#include <iostream>
#include <iomanip>
#include <string>
#include "stack.h"

using namespace std;


int main() {
    cout << boolalpha;      // http://www.cplusplus.com/reference/ios/boolalpha

    Stack<int> s1;

    s1.push(10);
    s1.push(20);

    cout << "s1.top()  : " << s1.top() << endl;

    s1.pop();
    cout << "s1.top()  : " << s1.top() << endl;

    s1.push(30);
    cout << "s1.top()  : " << s1.top() << endl;

    s1.pop();
    cout << "s1.top()  : " << s1.top() << endl;

    s1.pop();
    cout << "s1.empty(): " << s1.empty() << endl;

    s1.push(50);
    s1.push(60);
    cout << "s1.top()  : " << s1.top() << endl;

    cout << endl;

    Stack<int> s2(s1);
    cout << "s2.top()  : " << s2.top() << endl;

    s2.clear();
    s2.push(17);
    cout << "s2.top()  : " << s2.top() << endl;

    s2 = s1;    // assignment operator

    s1.clear();
    cout << "s1.empty(): " << s1.empty() << endl;

    cout << "s2.top()  : " << s2.top() << endl;
    s2.pop();
    cout << "s2.top()  : " << s2.top() << endl;
    s2.pop();
    cout << "s2.empty(): " << s2.empty() << endl;

    cout << endl;

    Stack <string> s3;
    s3.push("ABC");
    s3.push("DEF");

    cout << "s3.top()  : " << s3.top() << endl;
    s3.pop();
    cout << "s3.top()  : " << s3.top() << endl;
    s3.pop();
    cout << "s3.empty(): " << s3.empty() << endl;

    return 0;
}
