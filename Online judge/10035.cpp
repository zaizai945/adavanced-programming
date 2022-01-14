#include<iostream>
using namespace std;
int main(){
    long a,b;
    while(cin>>a>>b){
        if(a==0&&b==0)
            break;
        int count=0,x,y,c=0;
        while(a||b){
            int s=a%10+b%10+c;
            if(s>=10)
                c=1;
            else
                c=0;
            
            count+=c;
            a/=10;
            b/=10;
        }
        
        if(count==0)
            cout<<"No carry operation.\n";
        else if(count==1)
            cout<<"1 carry operation.\n";
        else
            cout<<count<<" carry operations.\n";
    }
    return 0;
}