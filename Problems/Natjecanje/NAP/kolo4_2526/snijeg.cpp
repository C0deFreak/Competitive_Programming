#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<string> grad;
    for(int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        grad.push_back(line);
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        int p;
        cin >> p;
        p--;
        if(p >= 0 && p<m) {
            int j=0;
            while(j<n && grad[j][p] == '.') {
                if(j==n-1 || grad[j+1][p] != '.') grad[j][p] = '*';
                j++;
            }  
        }
    }
    for(string s:grad) cout << s << endl;

    return 0;
}