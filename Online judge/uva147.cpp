#include<iostream>
#include<cstdio>

#define ll long long

using namespace std;

int m[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[30001];

int main()
{
    dp[0] = 1;
    for(int i = 10; i > -1; --i)
        for(int j = m[i]; j <= 30000; ++j)
            dp[j] += dp[j - m[i]];
    double x;
    cin >> x;
    while(x != 0) {
        int tmp = int (x * 100.00);
        if(tmp % 5 == 4)
            tmp++;
        printf("%6.2lf%17lld\n", x, dp[tmp]);
        cin >> x;
    }

    return 0;
}
