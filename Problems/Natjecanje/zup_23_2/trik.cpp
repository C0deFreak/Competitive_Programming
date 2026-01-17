#include <bits/stdc++.h>
using namespace std;

unordered_set<float> radius;
vector<tuple<float, float>> duzine;

void get_size() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    float a = sqrt(x1*x1 + y1*y1);
    float b = sqrt(x2*x2 + y2*y2); 
    float big=max(a, b);
    float small=min(a, b);
    

    float c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        
    if(sqrt(small*small+c*c) > big) {
        float s = (c+a+b)/2;
        float h = (2/c)*sqrt(s*(s-a)*(s-b)*(s-c));
        small=min(small, h);
        //cout << h << " s\n";
    }
    radius.insert(big);
    radius.insert(small);
    duzine.push_back({small, big});
    
    //cout << a << " " << b << "\n";

}

int main() {
    int n;
    cin >> n;
    int t=n;
    while(t--) {
        get_size();
    }
    
    int ans=1;
    for(float r:radius) {
        //cout << r << "\n";
        if(ans==n) break;
        int curr=0;
        for(int d=0; d<n; d++) {
            if (curr+(n-d)<ans) break;
            //cout << get<0>(duzine[d]) << " " << r << "\n";
            if(r >= get<0>(duzine[d]) && r <= get<1>(duzine[d])) curr++;
            //cout << "da ";
        }
        ans = max(ans, curr);

    }
    cout << ans << "\n";
    return 0;

}