#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int st, int mid, int en){
	/*
		Copy content of sorted arr[st...mid] and arr[mid+1...en]
		in two temporary arrays tempA and tempB. Finally merge tempA
		and tempB in original array.
	*/ 
	int lenA, lenB;
	lenA = (mid-st)+1;
	lenB = en-mid;
	int tempA[lenA], tempB[lenB];
	// tempA = arr[st - mid]
	for(int i=0; i<lenA; i++){
		tempA[i] = arr[st+i];
	}
	
	// tempB[] = arr[mid+1 - en]
	for(int j=0; j<lenB; j++){
		tempB[j] = arr[mid+1+j];
	}
	int i=0, j=0, idx=st;
	
	// Pick smallest among tempA[i] and tempB[j] and put at arr[idx]
	while(i<lenA and j<lenB){
		if(tempA[i] < tempB[j]){
			arr[idx++] = tempA[i++];
		}
		else{
			arr[idx++] = tempB[j++];
		}
	}
	// If elements are left in tempA
	while(i < lenA){
		arr[idx++] = tempA[i++]; 
	}
	
	// If elements are left in tempB
	while(j < lenB){
		arr[idx++] = tempB[j++];
	}
}
void mergeSort(int arr[], int st, int en){
	if(st < en){
		int mid = (st+en)/ 2;
		// Divide till the arr[st - en] is not sorted
		mergeSort(arr, st, mid);
		mergeSort(arr, mid+1, en);
		// merge sorted arrays arr[st - mid] and arr[mid+1 - en]
		merge(arr, st, mid, en);
	}
	return;
	
}
int main() {
	int arr[] = {2, 43, 12, 7, 5, 75, 62, 39};
	int n = sizeof(arr)/ sizeof(arr[0]);
	mergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}