#include<bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int main()
{
	int t, d, n, x, y, size;
	cin >> t;
	while(t--){
		cin >> d >> n;
		memset(arr, 0, sizeof(arr));
		while(n--){
			cin >> x >> y >> size;
			for(int i = x-d; i <= x+d && i <= 1024; i++){
				if(i < 0)
					i = 0;
				for(int j = y-d; j <= y+d && j <= 1024; j++){
					if (j < 0)
						j = 0;
					arr[i][j] += size;
				}
			}
		}
		int r = 0, c = 0, ans = 0;
		for(int i = 0; i < 1025; i++){
			for(int j = 0; j < 1025; j++){
				if(ans < arr[i][j]){
					ans = arr[i][j];
					r = i;
					c = j;
				}
			}
		}
		printf("%d %d %d\n", r, c, ans);
	}
	return 0;
}
