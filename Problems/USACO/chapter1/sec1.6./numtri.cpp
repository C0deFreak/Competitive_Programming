/*
ID: grgurin1
TASK: numtri
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int r;
vector<vector<int>> triangle;


int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    fin >> r;


    /* Zamisli trokut:
          7
         3 8
        8 1 0
    Mogo bi za svaku mogućnost preć ali primjeti da 
    kad zbrajaš za svaki zbroj imaš 2 mogućnosti n i n-1
    I da bi dobio najveći broj moraš uzet najveći od ta dva broja
    ako ideš po redovima dobiješ:
       7

       7
     10 15

       7
     10 15
    18 16 15 
    
    Ignorirali smo mogućnost (7+3)+1 jer postoji bolja (7+8)+1
    Ovaj novi trokut "zbroja" možemo stvoriti pri učitavanju običnog trokuta tako da
    za svaki element u redu (osim 0.) pogledamo n i n-1 vrijednosti, usporedimo ih,
    i učitanoj vrijednosti dodamo veću. Odgovor koja je najviša suma biti će najveći
    broj na dnu piramide*/
    triangle.resize(r);
    for(int i = 0; i<r; i++) {
        triangle[i].resize(i+1);
        for(int j = 0; j<i+1; j++) {
            fin >> triangle[i][j];
            if (i != 0) triangle[i][j] += max(triangle[i-1][max(0, j-1)], triangle[i-1][min(j, i-1)]);
        }
    }
    int ans = 0;
    for(auto n : triangle[r-1]) 
    ans = max(ans, n);

    fout << ans << "\n";
}
