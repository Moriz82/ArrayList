#include <iostream>
#include <stack>
#include "ArrayList.h"
#include "LinkedList.h"
using namespace std;


bool check(string str){
    stack<char> myStack;
    for (int i = 0; i < str.length(); ++i) {
        char c = str.at(i);
        if (c == '{' || c == '[' || c == '(') {
            myStack.push(c);
        }
        else {
            switch (c) {
                case '}':
                    if (myStack.top() == '{')
                        myStack.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (myStack.top() == '[')
                        myStack.pop();
                    else
                        return false;
                    break;
                case ')':
                    if (myStack.top() == '(')
                        myStack.pop();
                    else
                        return false;
                    break;
            }
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    cout<< check(str) << endl;

    return 0;
}