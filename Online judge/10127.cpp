#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int div=0,count=0;
        do{
            div*=10;
            div++;
            div%=n;
            count++;
        }while(div!=0);
        cout<<count<<endl;
    }
    return 0;
}