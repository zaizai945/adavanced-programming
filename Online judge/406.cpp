#include<iostream>
using namespace std;
int main(){
	int prime[1001];;
	int now[1001];
    for(int i=1;i<=1000;i++){
        prime[i]=0;
        now[i]=0;
    }
	for(int i=2;i<=1000;i++){
		for(int j=2*i;j<=1000;j+=i)
			prime[j]++;
    }
	int n,c;
	while(cin>>n>>c){
		cout<<n<<" "<<c<<":";
		int count=0;
		for(int i=1;i<=n;i++){
			if(!prime[i]){
				now[count+1]=i;
				count++;
			}
        }
		
		int s,t;
		if(count%2){
		    s=count/2-c+2;
		    t=count/2+c;
		}
		else{
		    s=count/2-c+1;
		    t=count/2+c;
		}
		if(s<1)
		    s=1;
		if(t>count)
		    t=count;
		
		for(int i=s;i<=t;i++)
            cout<<" "<<now[i];
	
		cout<<endl<<endl;
	}
	return 0;
}