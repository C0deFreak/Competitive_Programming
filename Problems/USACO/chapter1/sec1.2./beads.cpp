/*
ID: grgurin1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int n;
string beads;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    fin >> n;

    fin >> beads;
    beads = beads + beads;

    int ans = 0;
    int last = 0;
    int rn = 0;
    char color = beads[0];
    int last_color = -1;
    int addition = 0;

    /* Razlika između pythona i  ovoga je što je time za ovo O(2n)*/
    for(int i = 0; i<n*2; i++) {
        if (color == 'w') {
            color = beads[i];
        } else {
            /* Imamo last i rn koji su duljine tih djelova i 
            kad dođe do promjene boje oni se zbroje*/
            if(beads[i] != color) {
                if(beads[i] != 'w') {
                    
                    ans = max(ans, last+rn);
                    last = rn+addition;
                    rn = 0;
                    color = beads[i];
                    
                    /* Ovaj addition je važan zato što:
                    zamisli da imaš bbwrrbb
                    duljina prvog dijela je 3 (bbw)
                    duljina drugog dijela je 2 (rr), ali samo ako to gledamo kao rn
                    ako nam drugi dio služi kao last bit će 3 (wrr)
                    ovaj check ovdje provjerava jesu li slova prije početka rn bila bijela
                    ako jesu to znači da ćemo imati još taj dio za spojit u slučaju kad
                    rn bude služio kao last */
                    if(beads[i-1] == 'w') {
                        addition = i - last_color;
                    } else {
                        addition = 0;
                    }
                }
                last_color = i;
            }
            
        }
        rn++;
    }
    /* ako nije imalo promjene boje */
    ans = max(ans, last+rn);

    /* kako je lista zapravo uduplana, ako nam je odgovor viši od duljine liste
    znači da je trebao bit duljine n, ali je zbog udupljavanja veći*/
    fout << min(n, ans) << "\n";
}