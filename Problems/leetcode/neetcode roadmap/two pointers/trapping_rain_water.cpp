#include <bits/stdc++.h>
using namespace std;


// O(2n) jer se može dogodit da je najviša točka na početku, tako da trebaš doć do kraja i onda nazad na početak
class Solution {
public:
    int trap(vector<int>& height) {
        const int len = height.size();
        int l=0;
        int ans = 0;

        while(l<len-1) {
            // počneš s l i dokle god postoji veći stupac ispred njega se penješ
            while(l<len-1 && height[l] <= height[l+1]) {
                l++;
            }
            // kad dođeš do rn najvišeg s r ideš naprijed i tražiš stupac viši ili jednak l, usput dodaješ vodu
            int r = l+1;
            int curr = 0;
            while(r<len && height[r] < height[l]) {
                curr+= height[l] - height[r];
                r++;
            }
            // kad dođeš do tog stupca predaš tu vodu ans i l postane r osim ako nisi došo do kraja, a voda bi procurila
            if(r<len || height[r-1] >= height[l]) ans+=curr;
            else {
                // ako si došo do kraja a voda bi procurila, počneš gledat od kraja do zadnje trenutne visoke točke i dodaješ vodu
                // basiclly isto ali od zada i do tog high pointa
                int high = l;
                l = len-1;
                while(l>high+1) {
                    while(l>high+1 && height[l] <= height[l-1]) {
                        l--;
                    }
                    r = l-1;
                    curr = 0;
                    while(r>high && height[r] < height[l]) {
                        curr+= height[l] - height[r];
                        r--;
                    }
                    ans+=curr;
                    l = r;
                }
                r=len;
            }
            
            l = r;
        }   
        return ans;
    }
};
/*
možeš ubrzat ako ti l nije fiksan:

int l=0, r=height.size()-1;
int ans = 0;
int l_max=height[l], r_max=height[r];

while(l<r) {
    if(l_max < r_max) {
        l++;
        l_max=max(l_max, height[l]);
        ans+=l_max-height[l];
    } else {
        r--;
        r_max=max(r_max, height[r]);
        ans+=r_max-height[r];
    }
}
return ans;


Učinio si istu stvar ali istovremeno:
prvi dio gleda prema naprijed, l_max je ko l, a l je ko r u slučaju kad je naprijed
drugi dio gleda prema nazad, r_max je ko l, a r je ko r u slučaju nazad
znači umijesto da si prvo naprijed i onda nazad, ovo čini oboje u isto vrijeme dok se l i r ne nađu
*/