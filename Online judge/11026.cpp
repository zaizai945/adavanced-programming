//A grouping problem
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

ll dp[1001][1001];
ll input[1001];

int main()
{
    int n, m, tmp;
    while(cin >> n >> m) {
        if(n == 0 && m == 0)
            break;
        
        for(int i=0; i<1001; ++i)
            for(int j=0; j<1001; ++j) {
                if(j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }

        for(int i=1; i<=n; i++){
            cin >> tmp;
            input[i] = tmp%m;
        }
     
        dp[1][1] = input[1];
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++)
                dp[i][j] = (dp[i-1][j-1] * input[i] + dp[i-1][j]) % m;
        }
 
        ll ans = dp[n][1];
        for(int i=2; i<=n; i++)
            ans = max(ans, dp[n][i]);
        printf("%lld\n", ans);
    }
    return 0;
}