/*
ID: grgurin1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int months[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int ans[7] = {0};
int years;


int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    fin >> years;

    int day = 4;
    for(int y = 1900; y<1900+years; y++)
    for(int m = 0; m<12; m++) {
        
        if (((y%100 == 0 && y%400 == 0) || (y%100 != 0 && y%4 == 0)) && m == 2) {
            day = (day + months[m] + 1)%7;
        } else {
            day = (day + months[m])%7;
        }
        ans[day] += 1;
    }

    for(int i = 0; i<6; i++) fout << ans[i] << " ";
    fout << ans[6] << "\n";
}
