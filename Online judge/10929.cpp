#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char n[1001];
    while(cin>>n){
        if(n[0]=='0'&&strlen(n)==1)
            break;
            
        int a=0,b=0;
        for(int i=0;i<strlen(n);i++){
            if(i%2==1)
                a+=n[i]-'0';
            else
                b+=n[i]-'0';
        }

        if(a%11==b%11)
            cout<<n<<" is a multiple of 11.\n";
        else
            cout<<n<<" is not a multiple of 11.\n";
    }
    return 0;
}