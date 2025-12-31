/*
ID: grgurin1
TASK: ariprog
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int mx = 251;
int bisquares[2*mx*mx];
int n, m;

/* Checking if the numbers are in bisquares */
bool check(int a, int b) {
    for(int i=0; i<n; i++) {
        if (!bisquares[a+i*b]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin ("ariprog.in");
    ofstream fout ("ariprog.out");
    fin >> n >> m;

    /*Make a map of bisquares*/
    for(int y=0; y<=m; y++) {
        for(int x=0; x<=m; x++) {
            bisquares[y*y + x*x] = 1;
        }
    }

    
    bool empty = true;
    /* b will be multiplied n-1 anyways so we spare time by dividing it*/
    for(int b=1; b<=int((2*m*m)/(n-1)); b++) {
        /* since we will use b*(n-1) numbers, the max a can be is 2*m*m dividet by that*/
        for(int a=0; a<=(2*m*m)-((n-1)*b); a++) {
            if (check(a, b)) {
                empty = false;
                fout << a << " " << b << "\n";
            }
        }
    }
    if (empty) {
        fout <<"NONE\n";
    };

    return 0;
}