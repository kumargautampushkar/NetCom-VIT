#include <bits/stdc++.h>
#include "verification.hh"
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
    if(rem[0]=='1'){
        rem=bitwise_xor(rem,fx);
    }
    else{
        rem=bitwise_xor(rem,zero);
    }
        

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

string crc_generate(string div,string fx){
    //string dividend = div;
    for(int i=0;i<fx.size()-1;i++){
        div.push_back('0');
    }
    return binary_modulo(div,fx);
}


int main(int argc, char const *argv[])
{
    cout<<"Write the binary data"<<endl;
    string data;
    cin>>data;
    if((!isBinaryStringValid(data)))
    {
        cout<<"Error :The given input string is not binay"<<endl;
        cout<<"Terminating the program"<<endl;
        return 0;
    }
    
    cout<<"Write the encoding function"<<endl;
    string fx;
    cin >>fx;
    if(!(is_crc_function_valid(data,fx))){
        return 0;
    }

    string gen_crc=crc_generate(data,fx);
    cout<<gen_crc<<endl;

    return 0;
}
