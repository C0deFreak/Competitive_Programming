/*
ID: grgurin1
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int a, b, c;
const int mx = 20;
int ans[mx+1];

typedef struct Buckets  Buckets;
struct Buckets {
    int a[3];
};

int checked[mx+1][mx+1];

/* Pour how ever much the "add" bucket can take (the whole remove if it can)
    and remove that much from remove */
Buckets
pour(int diff, int add, int remove, int stale, Buckets bu) {
    Buckets s;
    s.a[add] = bu.a[add] + min(diff, bu.a[remove]);
    s.a[remove] = bu.a[remove] - min(diff, bu.a[remove]);
    s.a[stale] = bu.a[stale];

    return s;
}

void recurse(Buckets bu) {
    int diff;
    Buckets s;

    /* Add the current way to checked 
    (needs only 2 buckets cus the tird is just the diff of everything and the two others)
    and add C bucket to answers if A bucket is empty */
    checked[bu.a[1]][bu.a[2]] = 1;
    if(!bu.a[0]){
        ans[bu.a[2]] = bu.a[2]+1;
    } 

    /* Tries all the combinations (A->B, A->C, B->A ...)*/
    diff = a-bu.a[0];
    if (diff != 0) {
        s = pour(diff, 0, 1, 2, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
        s = pour(diff, 0, 2, 1, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
    }
    diff = b-bu.a[1];
    if (diff != 0) {
        s = pour(diff, 1, 0, 2, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
        s = pour(diff, 1, 2, 0, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
    }
    diff = c-bu.a[2];
    if (diff != 0) {
        s = pour(diff, 2, 0, 1, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
        s = pour(diff, 2, 1, 0, bu);
        if(!checked[s.a[1]][s.a[2]]) recurse(s);
    }

}


int main() {
    ifstream fin ("milk3.in");
    ofstream fout ("milk3.out");
    fin >> a >> b >> c;
    /* At the start only the C bucket is full */
    Buckets rn;
    rn.a[2] = c;
    rn.a[0] = 0;
    rn.a[1] = 0;
    recurse(rn);
    for(int i=0; i<c; i++) {
        if(ans[i]) {
            fout << ans[i]-1 << " ";
        }
    }
    fout << ans[c]-1 << "\n";
    return 0;
}

