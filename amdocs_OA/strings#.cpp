#include <iostream>
#include<string>

using namespace std;

bool isEqual(string s1, string s2){
    stack<char> stk1;
    stack<char> stk2;

    for(char ch: s1){

        if(ch == '#'){
            if(!stk1.empty()) stk1.pop();
        }
        else{
            stk1.push(ch);
        }
    }

    for(char ch: s2){

        if(ch == '#'){
            if(!stk2.empty()) stk2.pop();
        }
        else{
            stk2.push(ch);
        }
    }

    while(!stk1.empty() && !stk2.empty()){
        if(stk1.top() != stk2.top()){
            return false;
        }
        stk1.pop();
        stk2.pop();
    }

    return stk1.empty() && stk2.empty();
}

int main() {
    // Your code here
    // s1 = axx#bb#c
    // s2 = axbd#c#c
    // # does backspace

    // return s1 is equal to s2 ?
     string testCases[10][2] = {
        {"axx#bb#c", "axbd#c#c"},      // equal → true
        {"abc#d", "abzz##d"},          // equal → true
        {"a#c", "b"},                  // not equal → false
        {"ab##", "c#d#"},              // equal → true (both empty)
        {"xy#z", "xzz#"},              // equal → true
        {"bxj##tw", "bxo#j##tw"},      // equal → true
        {"a##c", "#a#c"},              // equal → true
        {"abc#e#d", "abdd##d"},        // equal → true
        {"aaa###", "#"},               // equal → true (both empty)
        {"abc#", "abd#"}               // equal → true (both "ab")
    };

    cout << "Backspace String Compare Test Results:\n\n";
    for (int i = 0; i < 10; i++) {
        string s1 = testCases[i][0];
        string s2 = testCases[i][1];
        bool result = isEqual(s1, s2);
        cout << "Test " << i + 1 << ": "
             << "s1 = \"" << s1 << "\", "
             << "s2 = \"" << s2 << "\" → "
             << (result ? "Equal ✅" : "Not Equal ❌") << endl;
    }

    return 0;
}