#include <bits/stdc++.h>
using namespace std;
 
/*
	Implementation of Quick Sort:-
	Strategy:- Divide and Conquer
	Type:- Recursive
	Stability:- Not stable
	Space Complexity:- O(1) => In-Place algorithm
	Time Complexity:-
		Best/Avg Case:- O(N*logN)
		Worst Case:- O(N*N)[when all elements are same or arrray is already sort inc/desc]
	Idea:- Choose a element randomly, call it Pivot. Place it at it's correct position
		in array such that all element left side of Pivot are smaller or equal to Pivot.
		Do the same for left and right subarray Recursively.	
*/
 
int partition(vector<int>& arr, int start, int end){
	int pivot = arr[end];
	int pIndex = 0;
	for(int i=0; i<end; i++){
		if(arr[i] <= pivot){
			int temp = arr[pIndex];
			arr[pIndex] = arr[i];
			arr[i] = temp;
			pIndex++;
		}
	}
	arr[end] = arr[pIndex];
	arr[pIndex] = pivot;
	return pIndex;
}
 
void quickSort(vector<int>& arr, int start, int end){
	if(start >= end) return;
	int pIndex = partition(arr, start, end);
	quickSort(arr, start, pIndex-1);
	quickSort(arr, pIndex+1, end);
}
int main() {
	vector<int> arr = {2, 7, 43, 12, 7, 5, 75, 62, 39, 2, 9, 5, 2, 7};
	int n = arr.size();
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}