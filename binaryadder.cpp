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

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a>>b;
    int c=0;
    /*
    string sum=binary_add_with_carry(a,b,c);
    //if(c==1) cout<<"carry generated"<<endl;
    sum=binary_add_carry(sum,c);
    */
    string sum = binary_add_wraparound(a,b);   
    cout<<sum<<endl;

    return 0;
}
