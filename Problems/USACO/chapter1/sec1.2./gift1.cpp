/*
ID: grgurin1
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<string, int> givers;
int n;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    fin >> n;
    string people[n];
    for(int i = 0; i<n; i++) {
        string name;
        fin >> name;
        people[i] = name;
        givers[name] = 0;
    }

    for(int i = 0; i<n; i++) {
        string giver;
        fin >> giver;
        
        int amount, times;
        fin >> amount >> times;
        if(times) {
            givers[giver] -= (amount - amount%times);
            amount = (int)amount / times;

            for(int j = 0; j<times; j++) {
                string name;
                fin >> name;
                givers[name] += amount;
            }
        }

    }

    for(auto item : people) {
        fout << item << " " << givers[item] << "\n";
    }
}