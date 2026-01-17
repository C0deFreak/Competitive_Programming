#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> nums;
    for(int i=0; i<n; i++) {
        int curr;
        cin >> curr;
        nums[curr] = true;
    }
    /* na kraju ćemo izbirat brojeve tako da nam mex ostane naj viši, tj za svako mijesto u k-1 ćemo 
       naštelit da nam je mex što veći, odgovor će nam bit min(mex(array), k-1) tj.
       ako nam je k == 4 ali nam je array 0, 1, 1, 3, 4 (nema 2) mex nam ne može bit veći od 2
       da smo imali 2 (0, 1, 2, 3, 4) mex arraya bio bi nam 5 ali najviše što može bit je 3 (k-1)
       Editorial kaže da je povezano s pigeonhole principle:
       ako imaš 367 ljudi, 2 sigurno dijele rođendan
       sad misliš što ako ima neki datum đe niko ne slavi, e pa onda ili 3 dijele jedan dan ili imaš dva para
    */
    
    for(int j=0; j<k; j++) {
        if(!nums[j]) {
            return j;
        }
    }

    return k-1;
}

int main() {
    int t;
    cin >> t;

    for(t; t>0; t--) {
        cout << solve() << "\n";
    }


    return 0;
}
