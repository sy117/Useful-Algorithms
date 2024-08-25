// Find the contiguous sub-array with maximum sum

#include <bits/stdc++.h>

using namespace std;

int kadane(int arr[], int n) {
	int curr_sum = arr[0], max_sum = arr[0];
	for(int i=1; i<n; i++) {
		curr_sum = max(arr[i], curr_sum + arr[i]);
		max_sum = max(max_sum, curr_sum);
	}
	return max_sum;
}

int main() {
	int n, ans;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	ans = kadane(a, n);
	cout << ans << "\n";
	return 0;
}