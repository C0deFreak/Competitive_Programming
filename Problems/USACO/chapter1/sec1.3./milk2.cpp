/*
ID: grgurin1
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;
int n;

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin >> n;
    vector<array<int, 2>> cows(n);
    for(int i = 0; i<n; i++) {
        fin >> cows[i][0] >> cows[i][1];
    }

    sort(cows.begin(), cows.end(), [](const array<int, 2>& x, const array<int, 2>& y) {
        return x[0] < y[0];
    });

    int milk = 0;
    int nomilk = 0;
    array<int, 2> current = cows[0];
    for(int j = 1; j<n; j++) {
        if (current[1] < cows[j][0]) {
            milk = max(milk, current[1]-current[0]);
            nomilk = max(nomilk, cows[j][0]-current[1]);
            current = cows[j];
        } else if(current[1] < cows[j][1]) current[1] = cows[j][1];
    }
    milk = max(milk, current[1]-current[0]);
    fout << milk << " " << nomilk << "\n";
}