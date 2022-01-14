#include<iostream>
using namespace std;
int main(){
    int c,under=1,over=1;
    long long tmp=1,data[100];
    for(int i=2;;i++){
        tmp*=i;
        if(tmp>6227020800)
            break;
        over++;
        if(tmp<=10000)
            under++;
        else
            data[over]=tmp;
    }
    under++;
    int n;
    while(cin>>n){  
        if((n>=0&&n<under)||(n<0&&((n*-1)%2)==0))
            cout<<"Underflow!\n";
        else if(n>over||(n<0&&((n*-1)%2)))
            cout<<"Overflow!\n";
        else
            cout<<data[n]<<endl;
    }
}