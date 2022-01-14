#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x,y;
    while(cin>>x>>y){
        if(x==0&&y==0)
            break;
        int ans=(int)(floor(sqrt(y))-ceil(sqrt(x))+1);
        cout<<ans<<endl;
    }
    
    return 0;
}