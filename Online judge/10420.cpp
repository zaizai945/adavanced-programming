#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string, int> data;
    string input;
    for(int i=0;i<n;i++){
        cin>>input;
        data[input]++;
        getline(cin,input);
    }
    map<string,int>::iterator it;
    for(it=data.begin();it!=data.end();++it)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;
}