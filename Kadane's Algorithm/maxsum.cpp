// Find the contiguous sub-array with maximum sum

#include <bits/stdc++.h>

using namespace std;

int kadane(int arr[],int n)
{
	int curr_max,max_ans;
	curr_max = max_ans = arr[0];
	for(int i=1;i<n;i++)
	{
		curr_max = max(arr[i], curr_max + arr[i]);
		max_ans = max(max_ans,curr_max);
	}
	return max_ans;
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
	ans = kadane(a,n);
	cout<<ans<<"\n";
	return 0;
}