#include <bits/stdc++.h>
using namespace std;


int main()
{
    int x, y;
    cin >> y >> x;

    vector<string> columns(x, "");
    vector<string> rows(y);

    cin.ignore();
    
    int last=0;
    int min_x=1;
    for(int i=0; i<y; i++) {
        string line;
        getline(cin, line);
        rows[i] = line;
        if(i) {
            if(rows[last] == rows[i]) last++;
            else {
                if(rows[0]== rows[i]) last=1, min_x=i;
                else last=0, min_x=i+1;
            }
        }
        for(int j=0; j<x; j++) {
            columns[j]+=line[j];
        }
    }

    last=0;
    int min_y=1;
    for(int j=1; j<x; j++) {
        if(columns[last] == columns[j]) last++;
        else {
            if(columns[0]== columns[j]) last=1, min_y=j;
            else last=0, min_y=j+1;
        }
    }

    cout << min_x << " " << min_y << "\n";


    return 0;
}
