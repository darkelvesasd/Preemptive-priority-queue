#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct scmp
{
	bool operator()(vector<int>a,vector<int>b)
	{
		if (a[1] == b[1])
		{
			return a[3] > b[3];
		}
		return a[1] < b[1];
	}
};
bool cmp(vector<int>a,vector<int>b)
{
	if (a[3] == b[3])
	{
		return a[1] > b[1];
	}
	return a[3] < b[3];
}
int main()
{
	vector<vector<int>>vv;
	priority_queue<vector<int>, vector<vector<int>>,struct scmp>pq;
	int a, b, c, d;
	while (cin>>a>>b>>c>>d)
	{
		vector<int>v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		vv.push_back(v);
	}
	sort(vv.begin(), vv.end(), cmp);
	int i = 0;
	int time = 0;
	while (i != vv.size() || !pq.empty())
	{
		while (i<vv.size()&&time == vv[i][3])
		{
			pq.emplace(vv[i]);
			i++;
		}
		if (!pq.empty())
		{
			vector<int>vt = pq.top();
			pq.pop();
			vt[2]--;
			if (vt[2] != 0)
			{
				pq.emplace(vt);
			}
			else
			{
				cout << vt[0]<<" "<<time+1<<endl;
			}
		}
		time++;
	}
	return 0;
}/*
 id val out in
 1 3 5 1
2 1 5 10
3 2 7 12
4 3 2 20
5 4 9 21
6 4 2 22*/
