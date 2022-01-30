#include <bits/stdc++.h>
using namespace std;

int kadane(int a[],int n)
{
	int curr_sum=a[0], max_sum=a[0];
	for(int i=1;i<n;i++)
	{
		curr_sum = max(a[i], curr_sum+a[i]);
		max_sum = max(max_sum, curr_sum);
	}
	return max_sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
			}
		}
		int curr_sum = INT_MIN;
		int max_sum = INT_MIN;
		for(int l=0;l<m;l++)
		{
			for(int r=l;r<m;r++)
			{
				int tmp[n];
				for(int i=0;i<n;i++)
				{
					if(l==r)
					{
						tmp[i]=arr[i][r];
					}
					else
					{
						tmp[i]+=arr[i][r];
					}
				}
				curr_sum = kadane(tmp,n);
				max_sum = max(max_sum,curr_sum);
			}
		}
		cout<<max_sum<<"\n";
	}
	return 0;
}