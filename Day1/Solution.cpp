#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream f("inp_Day1.txt");
	string s;
	vector<int> v1,v2;
	map<int,int> mp;
	//Q1 solution
	while(getline(f,s))
	{
		stringstream ss(s);
		string num;
		int i = 0;
		while(ss >> num)
		{
			if(i==0)
			{
				v1.push_back(stoi(num));
				i++;
			}
			else
			{
				v2.push_back(stoi(num));
				mp[stoi(num)]++;
			}
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int ans1=0;
	int n = v1.size();
	for(int i=0;i<n;i++)
	{
		ans1 = ans1 + abs(v1[i]-v2[i]);
	}
	cout<<ans1<<endl;

	//Q2 solution

	int ans2 = 0;
	for(int i=0;i<n;i++)
	{
		ans2 = ans2 + (v1[i]*mp[v1[i]]);
	}
	cout<<ans2<<endl;
}
