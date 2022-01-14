//Race
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1001][1001];

void run()
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=1000; ++i){
        for(int j=1; j<=i; j++)
            if(j==1)
                dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*j)%10056;
    }
}

int main()
{
    run();
    int c, r;
    scanf("%d", &c);
    for(int i=1; i<=c; ++i) {
        scanf("%d", &r);
        int ans=0;
        for(int j=1; j<=r; ++j)
            ans=(ans+dp[r][j])%10056;
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}