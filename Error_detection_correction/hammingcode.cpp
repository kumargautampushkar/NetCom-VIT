#include <bits/stdc++.h>
using namespace std;

string hamming_code(string data){
    int n=data.size();
    int r=0;
    while(pow(2,r)<n+r+1){
        r++;
    }
    int k=n+r;
    string ans="";
    int j=0;
    for(int i=1;i<=k;i++){
        if(i==pow(2,j)){
            ans.push_back('0');
            j++;
        }
        else{
            ans.push_back(data[i-j-1]);
        }
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    string k;
    cin>>k;
    cout<<hamming_code(k)<<endl;
    return 0;
}
