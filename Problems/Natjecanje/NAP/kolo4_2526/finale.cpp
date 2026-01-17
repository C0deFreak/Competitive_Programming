#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<tuple<int, string>> imena;
    while(n--) {
        string ime;
        int bodovi;

        cin >> ime >> bodovi;
        imena.push_back({bodovi, ime});
    }

    sort(imena.begin(), imena.end(), greater<>());
    for(int i=0; i<k; i++) cout << get<1>(imena[i]) << endl;

    return 0;
}