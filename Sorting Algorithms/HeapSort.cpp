/*
Heap Sort:
   Time Complexity : Best & Worst & Average => O(nLog(n))
   Space Complexity: O(1) 
   Stablitiy       : Not-Stable
   Is-In-Place     : In-Place
   When to use     : When the input array is large and stable sort is not 
                     required.		
   Remark          : It always guaranteed to be O(nLog(n)) with constant space 
                     which solves the problem of overflow of address space of a 
                     process which may occur in merge and quick sort(recursive stack).

*/

#include <bits/stdc++.h>
using namespace std;
 
int heapSize = 0;
 
void maxHeapify(int A[], int x) {
	// O(LogN)
	// x-> index of parent element
	int left, right;
	left = 2*x + 1;
	right = 2*x + 2;
	int largest = x;
	if(left < heapSize) {
		if(A[left] > A[largest])
		largest = left;
	}
 
	if(right < heapSize) {
		if(A[right] > A[largest]) {
			largest = right;
		}
	}
 
	if(largest != x) {
		swap(A[x], A[largest]);
		// recursively call effected sub-tree
		maxHeapify(A, largest);
	}
 
}
 
void buildMaxHeap(int A[], int n) {
	// O(NlogN)
	heapSize = n;
	for(int i=ceil(n/2); i>=0; i--) {
		maxHeapify(A, i);
	}
}
 
void heapSort(int A[], int n) {
    buildMaxHeap(A, n);
	while(heapSize>0) { // O(NlogN)
		swap(A[0], A[heapSize-1]);
		heapSize--;
		maxHeapify(A, 0); // logN
	}
}
 
int main() {
 
	int A[] = {12, 5, 7, 8, 9, 23, 45, 77, 17, 32};
	int n = 9;
	
	for(int i=0; i<n; i++) {
		cout << A[i] << " \n"[i==n-1];
	}
	heapSort(A, n);
	for(int i=0; i<n; i++) {
		cout << A[i] << " \n"[i==n-1];
	}
 
	return 0;
}

/*
Output:- [5, 7, 8, 9, 12, 17, 23, 45, 77]
*/