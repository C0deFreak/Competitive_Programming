#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (k==1 || k==n) cout << int((m+1)/2)+1 << "\n";
        else cout << int(m/2)+2 << "\n";
    }
    return 0;
}
