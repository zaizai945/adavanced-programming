#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[1001];
int dp[1001][1001];

int lcs(int i, int j)
{
    if(dp[i][j]==0) {
        if(i>=j)
            return 0;
        else if(s[i]==s[j])
            dp[i][j]=lcs(i+1, j-1);
        else
            dp[i][j]=1+min(min(lcs(i+1, j), lcs(i, j-1)), lcs(i+1, j-1));
    }
    return dp[i][j];
}

int main()
{
    int c;
    scanf("%d", &c);
    for(int i=1; i<=c; i++) {
        memset(dp, 0, sizeof(dp));
        scanf("%s", &s);
        printf("Case %d: %d\n", i, lcs(0, strlen(s)-1));
    }
    return 0;
}