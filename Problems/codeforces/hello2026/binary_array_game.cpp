#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    string barray;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, barray);


    if(barray[0] == '1' || barray[(n*2)-2] == '1') cout << "Alice";
    else cout << "Bob";

    return 0;
}