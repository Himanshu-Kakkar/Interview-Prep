#include <iostream>
#include<set>

using namespace std;

set<int> s;

void factors(int n){
    s.clear();
    s.insert(1);

    if(n==1){
        return;
    }

    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
}

int kthFactor(int n, int k){
    factors(n);
    s.insert(n);
    if(k > s.size()) return -1;

    while(--k){
        s.erase(s.begin());
    }
    return *s.begin();

}
int main() {
    // Your code here
     int testCases[10][2] = {
        {45, 1},
        {45, 3},
        {45, 6},
        {60, 7},
        {60, 12},
        {100, 4},
        {36, 5},
        {72, 8},
        {97, 2},
        {120, 9}
    };

    cout << "K-th Factor Results:\n";
    for (int i = 0; i < 10; i++) {
        int n = testCases[i][0];
        int k = testCases[i][1];
        int ans = kthFactor(n, k);
        cout << "Test " << i + 1 << ": n = " << n
             << ", k = " << k
             << " → " << ans << endl;
    }

    return 0;
}