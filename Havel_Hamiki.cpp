//cpp program to check whether given degree sequence represent a simple graph or not 

#include <bits/stdc++.h>
using namespace std;

bool validSequence(vector<int> v)
{
	int odeg=0,sum=0;
	priority_queue<int> q;
	for(int i=0;i<v.size();i++)
	{
		q.push(v[i]);
		sum+=v[i];
		if(v[i]&1)
		odeg++;
	}
	if((sum&1) ||(odeg&1))
	return false;
	vector<int> tmp;
	int x,k,flag=0;
	while(q.top()!=0)
	{
		k=q.top();
		q.pop();
		if(q.size()<k)
		return false;
		for(int i=0;i<k;i++)
		{
			x=q.top();
			q.pop();
			x--;
			tmp.push_back(x);
		}
		for(int i=0;i<k;i++)
		{
			if(tmp[i]<0)
			flag=1;
			q.push(tmp[i]);
		}
		tmp.clear();
		if(flag)
		break;
	}
	if(flag) return false;
	else return true;
}
int main() 
{
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	if(validSequence(v))
	{
		cout<<"Valid\n";
	}
	else
	{
		cout<<"Invalid\n";
	}
	return 0;
}
