/*
ID: grgurin1
TASK: pprime
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;
int a, b;
vector<int> ans;

// first and last numbers can only be odd
// you can make this even faster by skiping five (in odd) cus taht number then will be divisble by 5
#define ODD(n) for(int n = 1; n<=9; n+=2)
#define ANY(n) for(int n = 0; n<=9; n++)


// check if prime
bool prime(int n) {
    if (n < a || n > b) return false;
    
    for (int i = 3; i*i<=n; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    fin >> a >> b;
    int num;

    // One digit
    if (a < 10)
    ODD(i) {
        num = i;
        if (prime(num)) ans.push_back(num);
    }

    // Any palindrome that has even number of digits is divisible by 11
    // Because of that there is no need to check eny even number of digits except to add 11
    // Two digit
    if (a < 100 && b > 10)
    ans.push_back(11);

    // Three digit
    if (a < 1000 && b > 100)
    ODD(i) ANY(j) {
        num = i*100 + j*10 + i;
        if (prime(num)) ans.push_back(num);
    }

    // Five digit
    if (a < 100000 && b > 10000)
    ODD(i) ANY(j) ANY(k){
        num = i*10000 + j*1000 + k*100 + j*10 + i;
        if (prime(num)) ans.push_back(num);
    }

    // Seven digit
    if (a < 10000000 && b > 1000000)
    ODD(i) ANY(j) ANY(k) ANY(l){
        num = i*1000000 + j*100000 + k*10000 + l*1000 + k*100 + j*10 + i;
        if (prime(num)) ans.push_back(num);
    }

    for (auto a : ans) {
        fout << a << "\n";
    }
}