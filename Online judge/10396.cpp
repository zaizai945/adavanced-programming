#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> four, six, eight;
    for(int t=4; t<=8; t+=2){
        set<int> cal;
        int beg, bound, small;
        if(t==4){
            beg=10;
            bound=100;
            small=1000;
        } else if(t==6){
            beg=100;
            bound=1000;
            small=100000;
        } else{
            beg=1000;
            bound=10000;
            small=10000000;
        }
        for(int i=beg; i<bound; i++){
            for(int j=i+1; j<bound; j++){
                if(i%2==1&&j%2==1)
                    continue;
                if(i%10==0&&j%10==0)
                    continue;
                if(i*j<=small)
                    continue;

                int mul=i*j;
                mul-=(i+j);
                if(mul%9)
                    continue;

                int a[10], b[10];
                for(int k=0; k<10; k++)
                    a[k]=b[k]=0;

                int tmp=i;
                while(tmp){
                    a[tmp%10]++;
                    tmp/=10;
                }
                tmp=j;
                while(tmp){
                    a[tmp%10]++;
                    tmp/=10;
                }
                mul+=(i+j);
                while(mul){
                    b[mul%10]++;
                    mul/=10;
                }
                int flag=1;
                for(int k=0; k<10; k++){
                    if(a[k]!=b[k]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    cal.insert(i*j);
            }
        }
        if(t==4)
            four=cal;
        else if(t==6)
            six=cal;
        else
            eight=cal;
    }
    int n;
    set<int>::iterator it, ter;
    while(cin>>n){
        if(n==4){
            it=four.begin();
            ter=four.end();
        } else if(n==6){
            it=six.begin();
            ter=six.end();
        } else{
            it=eight.begin();
            ter=eight.end();
        }
        for(; it!=ter; it++)
            cout<<*it<<endl;
        cout<<endl;
    }
    return 0;
}