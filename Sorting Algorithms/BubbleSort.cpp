#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n){
	/*
		Key Idea:- In each iteration of outer loop maximum element in
		array should be placed at it's correct position, like biggest 
		bubble coming out of water.
		Type:- In place Sorting Algorithm
        Stablitiy:- Stable
		Time Complexity:- 
			Best Case:- O(N), when array is already Sorted
			Worst & Average Case:- O(N*N)
		Space Complexity:- O(1)
		Use Case:- In we want to place max K elements at it's correct position
	*/
	for(int k=0; k<n-1; k++){ // for each pass
		int flag = 0;
		for(int i=0; i<n-k-1; i++){ // for positioning current max to the end of unsorted array
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
				flag = 1;
			}
		}
		// After some passes the complete array is sorted
		if(flag == 0){
			break;
		}
	}
}


int main() {
	int arr[] = {2, 43, 12, 7, 5, 75, 62, 39};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	bubbleSort(arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}