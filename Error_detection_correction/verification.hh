#include <bits/stdc++.h>
using namespace std;

    
bool isBinaryStringValid(string const &s){
    bool ans=true;
    for(auto &it:s){
        if(!(it=='0' || it=='1'))
        {
            ans=false;
            break;
        }
    }
    return ans;
}

bool isBlockSizeValid(string const & s, int bs){
    if(s.size()%bs==0) return true;
    else return false;
}

bool is_leeding_zero(string const &fx){
    bool flag=true;
    if(fx[0]=='0')
    {
        flag=false;
    }
    return flag;   
}

bool is_crc_function_valid(string const &data, string const& fx)
{
    bool ans=true;
    
    if(!(isBinaryStringValid(fx))){
        ans=false;
        cout<<"Error : The given string by user is not a binary string"<<endl;
        return ans;
    }
    if(is_leeding_zero(fx)){
        ans=false;
        cout<<"Error : Leading zero detected in generating function"<<endl;
        return ans;
    }
   
    if(fx.size()<=1 && fx.size() >= data.size())
    {
        ans=false;
        cout<<"Error : The size of generating function is not valid"<<endl;
        return ans;
    }
    return ans;    
}
