#include <bits/stdc++.h>
using namespace std;

int pos_to_num(int x, int y, int n) {
    int b = 0;
    for(int i=n-1; i>=0; i--) {
        int size=pow(2, i);
        if(x>=size) b+=pow(2, 2*i+1), x-=size;
        if(y>=size) b+=pow(2, 2*i), y-=size;
    }
    return b;
}

tuple<int, int> num_to_pos(int k, int n) {
    vector<int> bin(n*2, 0);
    for(int b=n*2-1; b>=0; b--) {
        bin[b] = k%2;
        k/=2;
    }
    int x=0, y=0;
    int b=n-1;
    for(int i=0; i<n*2; i++) {
        if(i%2) {
            if(bin[i]) y+=pow(2, b);
            b--;
        } else {
            if(bin[i]) x+=pow(2, b);
        }
    }
    return {x, y};
}

int main()
{
    int n;
    cin >> n;

    int s, e;
    cin >> s;
    cin >> e;

    auto e_pos = num_to_pos(e, n);
    auto s_pos = num_to_pos(s, n);

    int ans = 0;
    if(get<1>(e_pos)<get<1>(s_pos)) {
        if(get<0>(e_pos)<get<0>(s_pos)) {
            for(int y=get<1>(e_pos); y<=get<1>(s_pos); y++) ans+=pos_to_num(get<0>(e_pos), y, n);
            for(int x=get<0>(e_pos)+1; x<=get<0>(s_pos); x++) ans+=pos_to_num(x, get<1>(s_pos), n);
        } else {
            for(int x=get<0>(e_pos); x>=get<0>(s_pos); x--) ans+=pos_to_num(x, get<1>(e_pos), n);
            for(int y=get<1>(e_pos)+1; y<=get<1>(s_pos); y++) ans+=pos_to_num(get<0>(s_pos), y, n);
        }
    } else {
        if(get<0>(s_pos)<get<0>(e_pos)) {
            for(int y=get<1>(s_pos); y<=get<1>(e_pos); y++) ans+=pos_to_num(get<0>(s_pos), y, n);
            for(int x=get<0>(s_pos)+1; x<=get<0>(e_pos); x++) ans+=pos_to_num(x, get<1>(e_pos), n);  
        } else {
            for(int x=get<0>(s_pos); x>=get<0>(e_pos); x--) ans+=pos_to_num(x, get<1>(s_pos), n);
            for(int y=get<1>(s_pos)+1; y<=get<1>(e_pos); y++) ans+=pos_to_num(get<0>(e_pos), y, n);   
        }
    }
    cout << ans << "\n";
    return 0;
}
