#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[], int n){
	/*
		Key Idea:- Place a card at it's correct position in a deck of sorted cards.
		Type:- In place Sorting Algorithm
        Stablitiy:- Stable
		Time Complexity:- 
			Best Case:- O(N), when array is already Sorted
			Worst & Average Case:- O(N*N), when array in reverse Sorted
		Space Complexity:- O(1)
		Use Case:- In we want to place K elements in a already sorted array.
	*/
	for(int k=1; k<n; k++){
		// Insert A[k] in the Sorted Segment arr[0, k-1]
		int ele = arr[k];
		int i=k-1;
		while(i>=0 and arr[i]>ele){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = ele;
	}
}

int main() {
	int arr[] = {2, 43, 12, 7, 5, 75, 62, 39};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	insertionSort(arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}