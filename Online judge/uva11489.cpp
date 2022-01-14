#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=0, c=0;
	cin >> t;
	while(t--){
		int arr[10000];
		string s;
		cin >> s;
		for(int i=0;i<s.length();++i)
			arr[i]=s[i]-'0';
		printf("Case %d: ", ++c);
		
		int mul=0, sum=0;
		for(int i=0;i<s.length();++i){
			sum += arr[i];
			if(!(arr[i]%3))
				mul++;
		}
		
		if(sum%3){
			bool find = false;
			for(int i=0;i<s.length();i++){
				if(arr[i]%3){
					if((sum-arr[i])%3 == 0){
						find = true;
						break;
					}
				}
			}
			if(find){
				if(mul%2)
					cout << "T" << endl;
				else
					cout << "S" << endl;
			}
			else{
				cout << "T" << endl;
			}
		}
		else{
			if(mul%2)
				cout << "S" << endl;
			else
				cout << "T" << endl;
		}
	}
	return 0;
}
