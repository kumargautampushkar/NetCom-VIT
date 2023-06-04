#include   <bits/stdc++.h>
using namespace std;

void singlebiterror_interactive(string &s){
    cout<<"Do you want to induce single bit error ?"<<endl;
    cout<<"If no then type -1"<<endl;
    cout<<"If yes then type any bit position "<<endl;
    int i;
    cin>>i;
    if(i<0 || i>=s.size()){
        cout<<"No error generated"<<endl;
        return;
    }
    if(s[i]=='0') s[i]='1';
    else s[i]='0';
}