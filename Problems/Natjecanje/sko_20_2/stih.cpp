#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    unordered_map<int, int> nums;
    int words=1;
    for(int i=0; i<=n; i++) {
        string line;
        getline(cin, line);
        bool add = false;
        for(char c:line) {
            if(!add && c != ' ') add=true;
            else if(add && c==' ') add=false, nums[words]=i, words++;
        }
        if(add) nums[words]=i, words++;
    }
    int k;
    cin >> k;

    for(int j=1; j<=k; j++) {
        int i;
        cin >> i;
        cout << nums[i] << "\n";
    }

}
