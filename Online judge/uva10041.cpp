#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n--){
		int arr[500];
		int t;
		cin >> t;
		for(int i=0;i<t;i++)
			cin >> arr[i];
		sort(arr, arr+t);
		int mid = arr[t/2];
		int ans=0;
		for(int i=0;i<t;i++)
			ans += abs(arr[i]-mid);
		cout << ans << endl;
	}
	return 0;
}
