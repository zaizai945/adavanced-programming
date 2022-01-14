#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define max 1000000
int main(){
    int prime[1001];
    for(int i=0; i<1001; i++)
        prime[i]=0;
    for(int p=2; p*p<=max; p++){
        if(prime[p]==0){
            for(int i=2*p; i*i<=max; i+=p)
                prime[i]=1;
        }
    }
    

    vector<int> fac;
    int n;
    while(cin>>n){
        if(n<2){
            cout<<"Not Exist!\n";
            continue;
        }
        fac.clear();
        priority_queue<long long, vector<long long>, greater<long long>> q;
        int tmp=n;
        for(int i=2; i<=1000&&tmp!=1; i++){
            if(prime[i]==0&&tmp%i==0&&tmp!=1){
                while(tmp%i==0)
                    tmp/=i;
                fac.push_back(i);
            }
        }
        if(tmp!=1)
            fac.push_back(tmp);
       
        long long base=1;
        long long pre;
        for(int i=0; i<fac.size(); i++)
            base*=fac[i];
        q.push(base);
        bool cmp=false;
        bool ans=false;
        while(!q.empty()){
            base=q.top();
            q.pop();
            if(base>n){
                ans=true;
                break;
            }
                
            if(cmp&&base==pre)
                continue;
            for(int i=0; i<fac.size(); i++){
                if(base*fac[i]<2000000){
                    q.push(base*fac[i]);
                }
            }
            pre=base;
            cmp=true;
        }
        if(ans)
            cout<<base<<endl;
        else
            cout<<"Not Exist!\n";
    }
    return 0;
}