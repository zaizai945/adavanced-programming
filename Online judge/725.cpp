#include<iostream>

using namespace std;


int main(){
    int n;
    bool first=false;
    while(cin>>n){
        if(n==0)
            break;
        
        bool flag=false;
        
        if(first)
            cout<<endl;

        for(int i=1234; i<49876; i++){
            if(i*n>=100000)
                break;

            int arr[10];
            for(int j=0; j<10; j++)
                arr[j]=0;

            int tmp=i;
            for(int j=0; j<5; j++){
                arr[tmp%10]++;
                tmp/=10;
            }
            tmp=i*n;
            for(int j=0; j<5; j++){
                arr[tmp%10]++;
                tmp/=10;
            }

            int count=0;
            for(; count<10; count++){
                if(arr[count]>1)
                    break;
            }
            if(count==10){
                flag=true;
                if(i<10000){
                    if(i*n<10000)
                        cout<<0<<i*n;
                    else
                        cout<<i*n;
                    cout<<" / "<<0<<i<<" = "<<n<<endl;
                }
                else
                    cout<<i*n<<" / "<<i<<" = "<<n<<endl;
            }

            if(!first)
                first=true;
        }
        if(!flag)
            cout<<"There are no solutions for "<<n<<".\n";
    }
    return 0;
}