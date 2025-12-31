/*
ID: grgurin1
TASK: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string group, ride;

int translate(string name){
    int res = 1;
    for(auto n : name) res *= int(n) - int('A') + 1;
    return res;
}


int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");

    fin >> group >> ride;

    if(translate(group)%47 == translate(ride)%47) {
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }

    return 0;
}