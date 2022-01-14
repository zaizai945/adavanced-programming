#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int in[10000], lis[10000], lds[10000], min[10000], arr[10000];

    while(cin>>n){
        for(int i=0; i<n; i++)
            cin>>in[i];

        int count=1;
        arr[0]=in[0];
        lis[0]=1;
        for(int i=1; i<n; i++){
            if(in[i]>arr[count-1]){
                arr[count]=in[i];
                lis[i]=++count;
            }
            else{
                int *tmp;
                tmp=lower_bound(arr, arr+count, in[i]);
                int temp = tmp-arr;
                arr[temp]=in[i];
                lis[i]=temp+1;
            }
        }
        

        arr[0]=in[n-1];
        lds[n-1]=1;
        count=1;
        for(int i=n-2; i>=0; i--){
            if(in[i]>arr[count-1]){
                arr[count]=in[i];
                lds[i]=++count;
            }
            else{
                int *tmp;
                tmp=lower_bound(arr, arr+count, in[i]);
                int temp = tmp-arr;
                arr[temp]=in[i];
                lds[i]=temp+1;
            }
        }

        for(int i=0; i<n; i++){
            if(lds[i]<lis[i])
                min[i]=lds[i];
            else
                min[i]=lis[i];
        }
        
        int max=-1;
        for(int i=0; i<n; i++){
            if(max<min[i])
                max=min[i];
        }
        cout<<max*2-1<<endl;
    }
    return 0;
}