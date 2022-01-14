#include<iostream>
#include<cstring>
#include<new>
#include<string>
#include<fstream>
#include<unistd.h>

using namespace std;

int num, cap, wei[1010], price[1010];
int *dp, **sol;

void knapsack(){
    for(int i = 0; i < cap+1; i++)
        dp[i] = 0;
    for(int i = 0; i < cap+1; i++)
        for(int j = 0; j < num; j++)
            sol[i][j] = 0;
    for(int i = 0; i < num; i++){
        for(int j = cap; j >= 0; j--){
            if(wei[i] <= j){
                if(dp[j] < dp[j - wei[i]] + price[i]){
                    dp[j] = dp[j - wei[i]] + price[i];
                    sol[j][i] = 1;
                }
            }
        }
    }
}

int main(){
    memset(wei, 0, 31);
    memset(price, 0, 31);

    cout << "Chose dataset ds1, ds2, ds3, or ds4 : ";
    string dir;
    cin >> dir;
    chdir(dir.c_str());

    fstream file;
    file.open("c.txt");
    file >> cap;
    file.close();

    file.open("w.txt");
    num = 0;
    while(file >> wei[num])
        num++;
    file.close();

    file.open("p.txt");
    num = 0;
    while(file >> price[num])
        num++;
    file.close();
    
    dp = new int[cap + 1];
    sol = new int*[cap + 1];
    for(int i = 0; i <= cap; i++)
        sol[i] = new int[num];
    knapsack();

    dir = "ans_" + dir + ".txt";
    ofstream myfile;
    myfile.open(dir.c_str());
	  myfile << dp[cap] << endl;
    int *ans = new int [num];
    for(int i = 0; i < num; i++)
        ans[i] = 0;
    for(int i = num-1, j = cap; i >= 0; i--){
        if(sol[j][i]){
            ans[i] = sol[j][i];
            j -= wei[i];
        }
    }
    for(int i = 0; i < num; i++)
        myfile << ans[i] << endl;
    myfile.close();

    delete [] dp;
    delete [] ans;
    for(int i = 0; i <= cap; i++)
        delete [] sol[i];
    delete [] sol;

    cout << "Program finished!\n";

    return 0;
}
