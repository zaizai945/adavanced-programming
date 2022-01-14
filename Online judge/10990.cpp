#include<iostream>
using namespace std;
#define ll long long
#define N 2000000

ll phi[N + 1];
int d[N + 1];

inline void set() {
    for(int i = 1; i <= N; i++)
        phi[i] = i;
    
    for(int p = 2; p <= N; p++) {
        if(phi[p] == p) {
            phi[p] = p - 1;
            for(int i = 2 * p; i <= N; i += p)
                phi[i] = phi[i] / p * (p - 1);
        }
    }
    
    d[1] = d[2] = 1;
    for(int i = 3; i <= N; i++)
        d[i] = 1 + d[phi[i]];
}

inline ll sodf(int m, int n) {
    ll s = 0;
    for(int i = m; i <= n; i++)
       s += d[i];
    return s;
}

int main() {
    set();
    
    int t, m, n;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cout << sodf(m, n) << endl;
    }

    return 0;
}