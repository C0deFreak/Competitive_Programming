#include <bits/stdc++.h>
using namespace std;

int solve() {
    int x, y, k;
    cin >> x >> y >> k;
    
    return max(2*int((x+k-1)/k)-1, 2*int((y+k-1)/k));
}


int main() {
    int t;
    cin >> t;

    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}