    #include <bits/stdc++.h>
    
    #define endl '\n'
    #define all(x) x.begin(),x.end()
    using namespace std;


    string binary_add(string a, string b)
    {
        assert(a.size()==b.size());
        reverse(all(a));
        reverse(all(b));
        int n= a.size();

        string ans;

        char carry='0';

        for(int i=0;i<n;i++){
            char sum;
            if(a[i]=='0' && b[i]=='0' & carry =='0')
            {
                sum='0';
                carry='0';
            }
            
            else if(a[i]=='0' && b[i]=='0' & carry =='1')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            
            else if(a[i]=='1' && b[i]=='0' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='0')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='1')
            {
                sum='1';
                carry='1';
            }
            ans.push_back(sum);
        }
        reverse(all(ans));
        return ans;

    }

    string binary_add_with_carry(string a, string b,int &c)
    {
        assert(a.size()==b.size());
        reverse(all(a));
        reverse(all(b));
        int n= a.size();

        string ans;

        char carry;
        if(c==0) carry='0';
        else carry='1';

        for(int i=0;i<n;i++){
            char sum;
            if(a[i]=='0' && b[i]=='0' & carry =='0')
            {
                sum='0';
                carry='0';
            }
            
            else if(a[i]=='0' && b[i]=='0' & carry =='1')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            
            else if(a[i]=='1' && b[i]=='0' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='0')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='1')
            {
                sum='1';
                carry='1';
            }
            ans.push_back(sum);
        }
        if(carry=='0') c=0;
        else c=1;
        reverse(all(ans));
        return ans;

    }

    string binary_add_carry(string a,int &c)
    {
        string b;
        for(int i=0;i<a.size();i++){
            b.push_back('0');
        }
        assert(a.size()==b.size());
        reverse(all(a));
        reverse(all(b));
        int n= a.size();

        string ans;

        char carry;
        if(c==0) carry='0';
        else carry='1';

        for(int i=0;i<n;i++){
            char sum;
            if(a[i]=='0' && b[i]=='0' & carry =='0')
            {
                sum='0';
                carry='0';
            }
            
            else if(a[i]=='0' && b[i]=='0' & carry =='1')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' & carry =='0')
            {
                sum='1';
                carry='0';
            }
            
            else if(a[i]=='1' && b[i]=='0' & carry =='1')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='0')
            {
                sum='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' & carry =='1')
            {
                sum='1';
                carry='1';
            }
            ans.push_back(sum);
        }
        if(carry=='0') c=0;
        else c=1;
        reverse(all(ans));
        return ans;

    }

    string binary_add_wraparound(string a, string b){
        int c=0;
        string sum=binary_add_with_carry(a,b,c);
        sum=binary_add_carry(sum,c);
        return sum;
    }

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

    void printvector(vector <string> &v){
        for(auto &it:v){
            cout<<it<<endl;
        }
    }

    void onecompliment(string &str){
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]=='0') str[i]='1';
            else str[i]='0';
        }
    }

    vector <string> vector_generator(string &s, int bs){
        vector <string> v;
        int k=s.length()/bs;
        for(int i=0;i<k;i++){
            string temp = s.substr(i*bs,bs);
            v.push_back(temp);
        }

        return v;
    }

    string blank_string_gen(int n){
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('0');
        }
        return s;
    }
    string checksum(string &s, int bs){
        vector <string> v = vector_generator(s,bs);
        int k=s.length()/bs;
        
        string cks=blank_string_gen(bs);
        for(int i=0;i<k;i++){
            cks=binary_add_wraparound(v[i],cks);            
        }
        onecompliment(cks);
        return cks;

    }

    string appendchecksum(string const &s, string const &cks)
    {
        string str=s+cks;
        return str;   
    }

    bool checkchecksum(string &data , int bs){
        string chk=checksum(data,bs);
        cout<<"Checking data integrity"<<endl;
        cout<<"Total checksum of recieved data is"<<chk <<endl;
        bool flag=true;
        for(int i=0;i<chk.size();i++){
            if(chk[i]!='0'){
                flag=false;
                break;
            }
        }
        return flag;
    }

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

    int main(int argc, char const *argv[])
    {
        /* code */

        cout<<"Please write the binary string to be encoded with checksum"<<endl;
        string s;
        cin>>s;
        cout<<endl;

        if(!isBinaryStringValid(s)){
            cout<<"Error, the string "<<s<<" is not valid"<<endl;
            cout<<"Program terminated"<<endl;
            return 0;
        }

        cout<<"Please write the block size"<<endl;
        int bs;
        cin>>bs;
        cout<<endl; 

        if(!isBlockSizeValid(s,bs)){
            cout<<"Error, the block size entered is not divisible by string length"<<endl;
            cout<<"Prorgam terminated"<<endl;
            return 0;
        }

        string cks=checksum(s,bs);
        cout<<"Checksum of the transmitted data is " <<cks<<endl;
        cout<<endl; 

        string data=appendchecksum(s,cks);
        singlebiterror_interactive(data);
        cout<<endl;
        cout<<"Data after running error generation module is "<<data<<endl;
        
        cout<<endl;
        //cout<<"Checking data"<<endl;
        bool data_integrity=checkchecksum(data,bs)<<endl;
        
        if(data_integrity){
            cout<<"No error detected"<<endl;
        }
        else{
            cout<<"Error detected"<<endl;
        }
        
        
        return 0;
    }

//100010000001