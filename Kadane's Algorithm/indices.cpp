// Find start index and end index of subarray with maximum sum

#include <bits/stdc++.h>

using namespace std;

void findIndices(int arr[],int n)
{
	int curr_max = 0;
	int max_ans = INT_MIN;
	int st=0,en=0,s=0;
	for(int i=0;i<n;i++)
	{
		curr_max = curr_max + arr[i];
		if(curr_max > max_ans)
		{
			max_ans = curr_max;
			st=s;
			en=i;
		}
		if(curr_max < 0)
		{
			curr_max = 0;
			s=i+1;
		}
	}
	cout<<"Start = "<<st<<" ,End = "<<en<<"\n";
}
int main()
{
	int n,ans;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	findIndices(a,n);
	return 0;
}