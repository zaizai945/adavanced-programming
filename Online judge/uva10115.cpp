#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void cts(string &s, char *c)//trans char to string 
{
	s = "";
	for(int i=0;i<strlen(c);i++)
		s = s + c[i];
}

void edit(string &s, string f, string r, int p)
{
	string x, t;
	x=t="";
	for(int i=0;i<p;i++)
		x=x+s[i];
	for(int j=p+f.length();j<s.length();j++)
		t=t+s[j];
	s=x+r+t;
}

int main()
{
	int n;
	char c[300];
	
	cin >> n;
	while(n){
		getchar();
		string f[10], r[10];
		string s;
		for(int i=0;i<n;i++){
			gets(c);
			cts(f[i], c);
			gets(c);
			cts(r[i], c);
		}
		gets(c);
		cts(s, c);

		int pos;
		for(int i=0;i<n;i++){
			while(pos = s.find(f[i]), pos != -1){//exist
				edit(s, f[i], r[i], pos);
			}
		}
		cout << s << endl;
		cin >> n;
	}
	return 0;
}
