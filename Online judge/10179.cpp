#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

int arr[100001];
vector<int> prime;

int main() {
	memset(arr, 0, 100000);
	for (int i = 2; i <= 100000; i++) {
		if (!arr[i])
			for (int j = i*2; j <= 100000; j += i)
				arr[j] = 1;
	}

	int num;
	scanf("%d", &num);
	while (num) {
		prime.clear();
		int tmp = num;
		for (int i = 2; i <= 100000 && i <= num; i++){
			if (arr[i] == 0){
				if(tmp%i == 0){
					prime.push_back(i);
					while (tmp%i == 0)
						tmp /= i;
				}
			}
		}
		if (tmp > 100000) {
			prime.push_back(tmp);
		}
		int  ans = num;
		for (int i = 0; i < prime.size(); i++) {
			ans = ceil( ((double)ans / (double)prime[i]) * (double)(prime[i] - 1));
		}
		printf("%d\n", ans);
		scanf("%d", &num);
	}
	

	return 0;
}
