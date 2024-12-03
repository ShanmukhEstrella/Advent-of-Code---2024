#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream f("inp_Day2.txt");
	string s;
	vector<vector<int>> v(1000);
	int i = 0;
	while(getline(f,s))
	{
		stringstream ss(s);
		string num;
		while(ss >> num)
		{
				v[i].push_back(stoi(num));
		}
		i++;
	}
	int ans=0;
	for(int i=0;i<1000;i++)
	{
		int n = v[i].size();
		vector<int> dummy = v[i];
		for(int j = 0; j<n; j++) //Comment for Part 1
		{                        //Comment for Part 1
			v[i].erase(v[i].begin()+j);    //Comment for Part 1
			if(is_sorted(v[i].begin(),v[i].end()) || is_sorted(v[i].begin(),v[i].end(),greater<int>()))  //Comment for Part 1
			{
				int j = v[i].size();
				bool b = true;
				for(int k=0;k<j-1;k++)
				{
					if(abs(v[i][k]-v[i][k+1]) >=1 && abs(v[i][k]-v[i][k+1]) <=3)
					{
						;
					}
					else
					{
						b = false;
						break;
					}
				}
				if(b) 
				{
					ans++;
					break;
				}
			}
			v[i] = dummy; //comment for Part 1
		}
	}
	cout<<ans<<endl;
}
