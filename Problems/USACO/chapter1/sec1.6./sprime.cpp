/*
ID: grgurin1
TASK: sprime
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;


bool is_prime(int num) {
    if (num % 2 == 0) return false;
    for(int i = 3; i*i<=num; i+=2) {
        if(num % i == 0) return false;
    }
    return true;
}

// you only need to add odd numbers cus even numbers are divisible by 2
// can be made faster by skipping 5
void n_prime(int num) {
    for(int i = 1; i<=9; i+=2) {
        int next = num*10 + i;
        if (is_prime(next)) {
            if (next > pow(10, n-1)) ans.push_back(next);
            else n_prime(next);
        }
    }
}


int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    fin >> n;
    // if we chop the ribs, the last num (firs added) can only be prime
    n_prime(2);
    n_prime(3);
    n_prime(5);
    n_prime(7);

    for(auto a : ans) {
        fout << a << "\n";
    }

    return 0;
}
