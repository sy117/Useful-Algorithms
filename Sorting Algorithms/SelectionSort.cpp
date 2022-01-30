#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
	/*
		Key Idea:- In each iteration of outer loop minimum element among unsorted
		array should be placed at it's correct position.
		Type: In place Sorting Algorithm
        Stablitiy:- Not-Stable
		Time Complexity:- Best & Worst & Average => O(N*N)
		Space Complexity:- O(1)
		Use Case:- In we want to place min K elements at it's correct position
	*/
	for(int i=0; i<n-1; i++){ // i-> used for correct pos and indicates that array is Sorted till point i
		int minIndex = i;
		for(int j=i+1; j<n; j++){ // j-> find minimum element in range [i+1, n-1]
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		if(i != minIndex){
			swap(arr[i], arr[minIndex]);
		}
	}
}


int main() {
	int arr[] = {2, 43, 12, 7, 5, 75, 62, 39};
	int n = sizeof(arr)/ sizeof(arr[0]);
	selectionSort(arr, n);
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}