#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int data[10],ans[20];
	for(int i=0;i<20;i++)
		ans[i]=0;//0 is order
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)
			cin>>data[j];
		bool less=true,greater=true;
		int pre=data[0];
		for(int j=1;j<10;j++){
			if(less&&pre<data[j])
				less=false;
			if(greater&&pre>data[j])
				greater=false;
			if(!greater&&!less){
				ans[i]=1;
				break;
			}
			pre=data[j];
		}
	}
	cout<<"Lumberjacks:\n";
	for(int i=0;i<n;i++){
		if(ans[i]==0)
			cout<<"Ordered\n";
		else
			cout<<"Unordered\n";

	}
}