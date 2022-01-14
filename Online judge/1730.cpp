#include<iostream>
using namespace std;
#define ll long long

int main() {
    ll n, s, l, r, t;
    while(cin >> n) {
        if(!n)
            break;
            
        
        s = 0; l = 1; r = 0; t = 0;
        while(l <= n){
            t = n / l;
            r = n / t;
            s += t * (l + r) * (r - l + 1) / 2;
            l = r + 1;
        }
        cout << --s << endl;
    }
    return 0;
}