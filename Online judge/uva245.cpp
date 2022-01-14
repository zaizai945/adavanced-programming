#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> v;
	string s;
	getline(cin, s);
	while(s[0] != '0'){
		for(int i=0; i<s.length(); i++){
			if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
				string tmp = "";
				while((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
					tmp = tmp + s[i];
					i++;
				}
				v.push_back(tmp);
				cout << tmp;
				i--;
			}
			else if(s[i] >= '0' && s[i] <= '9'){
				int p = 0;
				while(s[i] >= '0' && s[i] <= '9'){
					p = p*10 + s[i] - '0';
					i++;
				}
				i--;
				string tmp = v[v.size() - p];
				cout << tmp;
				v.erase(v.begin()+v.size()-p);
				v.push_back(tmp);
			}
			else
				cout << s[i];
		}
		cout << endl;
		getline(cin, s);
	}
	return 0;
}
