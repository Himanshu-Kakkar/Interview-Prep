#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

int getSubstringCount(string s) {
    vector<int> groups;
    int n = s.size();
    int count = 1;

    // Step 1: Count consecutive groups of same character
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            count++;
        else {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count);

    // Step 2: For each adjacent group pair, add min(g1, g2)
    int ans = 0;
    for (int i = 0; i < groups.size() - 1; i++) {
        ans += min(groups[i], groups[i + 1]);
    }

    return ans;
}

int main() {
    vector<string> testCases = {
        "01", "0011", "011001", "000111", "101010",
        "111000", "1100", "0000", "010101", "11001100"
    };

    for (string s : testCases) {
        cout << "s = " << s << " → " << getSubstringCount(s) << endl;
    }

    return 0;
}
