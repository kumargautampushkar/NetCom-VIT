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

string popfront(string str){
    string temp="";
    if(str.size()==0){
        cout<<"string size is zero, cannot pop back"<<endl;
        return "";
    }
    else{
        for(int i=1;i<str.size();i++){
            temp.push_back(str[i]);
        }
    }
    return temp;
}

string binary_modulo(string div,string fx){
    int p= div.size();
    int q = fx.size();
    string zero="";
    for(int i=0;i<q;i++){
        zero.push_back('0');
    }

    string rem= div.substr(0,q);
    rem=bitwise_xor(rem,fx);

    for(int i=0;i<p-q;i++){
        //cout<<div[i+4];
        rem=popfront(rem);
        rem.push_back(div[i+4]);
        if(rem[0]=='1'){
            rem=bitwise_xor(rem,fx);
        }
        else{
            rem=bitwise_xor(rem,zero);
        }
    }
    
    return popfront(rem);
}


int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<binary_modulo(s1,s2)<<endl;

    return 0;
}
/*
string crc(string div, string fx){
    string zero=fx;
    for(int i=0;i<fx.size();i++){
        zero[i]='0';
    }
    for(int i=0;i<fx.size()-1;i++){
        div.push_back('0');
    }
    string ans=div.substr(0,fx.size());
    if(ans[0]=='1'){
        ans=bitwise_xor(ans,fx);
    }
    else{
        ans=bitwise_xor(ans,zero);
    }
    for(int i=0;i<div.size()-1;i++){
        if(ans[0]=='1'){
            ans=popfront(ans);
            ans.push_back(div[i+4]);
            ans=bitwise_xor(ans,fx);
        }else{
            ans=popfront(ans);
            ans.push_back(div[i+4]);
            ans=bitwise_xor(ans,zero);
        }
    }
    ans=popfront(ans);
    return ans;

}

string binary_div(string div, string fx){
    string zero=fx;
    for(int i=0;i<fx.size();i++){
        zero[i]='0';
    }

    // for(int i=0;i<fx.size()-1;i++){
    //     div.push_back('0');
    // }

    string ans=div.substr(0,fx.size());
    if(ans[0]=='1'){
        ans=bitwise_xor(ans,fx);
    }
    else{
        ans=bitwise_xor(ans,zero);
    }
    for(int i=0;i<div.size()-1;i++){
        if(ans[0]=='1'){
            ans=popfront(ans);
            ans.push_back(div[i+4]);
            ans=bitwise_xor(ans,fx);
        }else{
            ans=popfront(ans);
            ans.push_back(div[i+4]);
            ans=bitwise_xor(ans,zero);
        }
    }
    ans=popfront(ans);
    return ans;

}

*/

