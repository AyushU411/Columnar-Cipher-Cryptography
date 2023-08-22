//Code for Columnar Transposition cipher encryption as well as decryption
#include <bits/stdc++.h>
using namespace std;
string encrypt(string &s,float key)
{
    int l=s.length(),k=0;
    int r=ceil(l/key);
    vector<vector<char>> grid(r,vector<char>(key,' '));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<key;j++)
        {
            grid[i][j]=s[k++];
        }
        if(k>=l)
        break;
    }
    string enc="";
    for(int i=0;i<key;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(grid[j][i]==' ')
            continue;
            enc+=grid[j][i];
        }
    }
    return enc;
}
string decrypt(string &s,float key)
{
    int l=s.length(),k=0;
    int r=ceil(l/key);
    vector<vector<char>> grid(r,vector<char>(key,' '));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<key;j++)
        {
            grid[i][j]=s[k++];
        }
        if(k>=l)
        break;
    }
    string dec="";
    k=0;
    for(int i=0;i<key;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(grid[j][i]==' ')
            continue;
            grid[j][i]=s[k++];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<key;j++)
        {
            dec+=grid[i][j];
        }
    }
    return dec;
}
int main()
{
    string s1,s="One Piece is the best";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
        s1+=s[i];
    }
    int key=4;
    string enc=encrypt(s1,key);
    cout<<enc<<endl;
    string dec=decrypt(enc,key);
    cout<<dec<<endl;
    return 0;
}
