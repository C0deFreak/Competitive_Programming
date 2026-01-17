#include <bits/stdc++.h>

using namespace std;
int main() {
    string vrijeme;
    int temp;
    cin >> vrijeme;
    cin >> temp;

    if(vrijeme == "kisa" && temp <= 0) cout << "Pazi led!\n";
    else cout << "Sigurno!\n";
    
    return 0;
}