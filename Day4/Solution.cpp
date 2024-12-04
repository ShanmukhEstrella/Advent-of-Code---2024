#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    vector<vector<char>> v(140);
    int j = 0;
    ifstream inputfile("inp_Day4.txt");
    while (getline(inputfile, line))
    {
        for(auto i : line)
        {
            v[j].push_back(i);
        }
        j++;
    }
    int ans = 0;
    for(int i =0;i<140;i++)
    {
        for(int j=0;j<140;j++)
        {
            if(v[i][j]=='X' && (j+1<140 && v[i][j+1]=='M') && (j+2<140 && v[i][j+2]=='A') && (j+3<140 && v[i][j+3]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (j-1>=0 && v[i][j-1]=='M') && (j-2>=0 && v[i][j-2]=='A') && (j-3>=0 && v[i][j-3]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (i+1<140 && v[i+1][j]=='M') && (i+2<140 && v[i+2][j]=='A') && (i+3<140 && v[i+3][j]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (i-1>=0 && v[i-1][j]=='M') && (i-2>=0 && v[i-2][j]=='A') && (i-3>=0 && v[i-3][j]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (i-1>=0 && j-1>=0 && v[i-1][j-1]=='M') && (i-2>=0 && j-2>=0 && v[i-2][j-2]=='A') && (i-3>=0 && j-3>=0 && v[i-3][j-3]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (j+1<140 && i+1<140 && v[i+1][j+1]=='M') && (j+2<140 && i+2<140 && v[i+2][j+2]=='A') && (j+3<140 && i+3<140 && v[i+3][j+3]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (i-1>=0 && j+1<140 && v[i-1][j+1]=='M') && (i-2>=0 && j+2<140 && v[i-2][j+2]=='A') && (i-3>=0 && j+3<140 && v[i-3][j+3]=='S'))
            {
                ans++;
            }
            if(v[i][j]=='X' && (j-1>=0 && i+1<140 && v[i+1][j-1]=='M') && (i+2<140 && j-2>=0 && v[i+2][j-2]=='A') && (i+3<140 && j-3>=0 && v[i+3][j-3]=='S'))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    ans=0;
    for(int i =0;i<140;i++)
    {
        for(int j=0;j<140;j++)
        {
            if(v[i][j]=='A')
            {
                if(i-1>=0 && j-1>=0 && i+1<140 && j+1<140)
                {
                    if((v[i-1][j-1]=='M' && v[i+1][j+1]=='S') || (v[i-1][j-1]=='S' && v[i+1][j+1]=='M'))
                    {
                        if((v[i+1][j-1]=='M' && v[i-1][j+1]=='S') || (v[i+1][j-1]=='S' && v[i-1][j+1]=='M'))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
