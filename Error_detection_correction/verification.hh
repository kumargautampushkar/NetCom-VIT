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