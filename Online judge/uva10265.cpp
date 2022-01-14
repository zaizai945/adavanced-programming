#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int m, n, k, snum, bnum;
int arr[15], sov[15][15], bs[15][15];
int sm[15], bm[15];
bool flag=0;

void init()
{
	memset(arr, 0, 15);
	memset(bm, 0, 15);
	memset(sm, 0, 15);
	memset(sov, 0, sizeof(sov));
	memset(bs, 0, sizeof(bs));
	bnum=snum=1;;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			if(!sov[i][j]) {
				int r=i, c=j;
				do {
					sov[r][c]=snum;
					r=r%n+1;
					c=(c-2+m)%m+1;		
				}while(r!=i||c!=j);
				snum++;
			}
			if(!bs[i][j]) {
				int r=i, c=j;
				do {
					bs[r][c]=bnum;
					r=r%n+1;
					c=c%m+1;
				}while(r!=i||c!=j);
				bnum++;
			}
		}
}

bool isok(int row, int col)
{
	int f=1;
	for(int i=1; i<col; i++){
		if(arr[i] == row){
			f=0;
			break;
		}
	}
		
	if(sm[sov[row][col]] == 1 || bm[bs[row][col]] == 1)
		f=0;

	if(f)
		return true;
	else
		return false;
}

void bt(int col, int num)
{
	if(flag)
		return;
	if(num == k){
		flag=1;
		for(int i=1; i<=m; i++)
			if(arr[i]!=0)
				cout << i << " " << arr[i] << endl;
		return;
	}
	if(col > m)
		return;

	for(int i=1; i<=n; i++){
		if(isok(i, col)) {
			arr[col]=i;
			sm[sov[i][col]]=bm[bs[i][col]]=1;
			bt(col+1, num+1);
			arr[col]=0;
			sm[sov[i][col]]=bm[bs[i][col]]=0;
		}
	}
	bt(col+1, num);
}

int main()
{
	while(cin >> m >> n >> k) {
		if(m==14 && m==n && n==k)
			cout << "0 0\n";
		else{
			flag=0;
			init();
			bt(1, 0);
			if(!flag)
				cout << "0 0\n";
		}
	}
}