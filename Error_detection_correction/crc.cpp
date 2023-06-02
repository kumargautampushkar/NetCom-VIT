#include <bits/stdc++.h>
using namespace std;


string bitwise_xor(string const &s1, string const &s2)
{
    if(s1.size()!= s2.size())
    {
        cout<<"Error: Both the strings are not equal\nReturning empty string\nXOR operation unsuccessful";
        return "";
    }
    string ans=s1;
    for(int i=0;i<s1.size();i++){
        if(s1[i] == s2[i]){
            ans[i]='0';
        }
        else{
            ans[i]='1';
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1>>s2;

    string x = bitwise_xor(s1,s2);
    cout<<x<<endl;
    return 0;
}
