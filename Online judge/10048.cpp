//audiophobia
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define infin 1000000000

int dp[101][101];

int main()
{
    int s, q, c, t = 1;
    while(cin >> c >> s >> q) {
        if(s == 0 && q == 0 && c == 0)
            break;

        for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++)
                dp[i][j] = infin;

        int c1, c2, d;
        for(int i = 0; i < s; i++) {
            cin >> c1 >> c2 >> d;
            if(dp[c1][c2] == infin || d < dp[c1][c2])
                dp[c1][c2] = dp[c2][c1] = d;
        }

        //floyd algorithm
        for(int k = 1; k <= c; k++)
            for(int i = 1; i <= c; i++)
                for(int j = 1; j <= c; j++) {
                        if(i != j)
                            dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                }

        if(t > 1)
            cout << endl;
        cout << "Case #" << t++ << endl;
        for(int i = 0; i < q; ++i) {
            cin >> c1 >> c2;
            if(dp[c1][c2] == infin)
                cout << "no path\n";
            else
                cout << dp[c1][c2] << endl;
        }
    }

    return 0;
}