

#include <bits/stdc++.h>

using namespace std;


void merge(int arr[], int l, int m, int r) {
    int nLeft = m-l+1;
    int nRight = r-m;
    
}

void mergeSortRecur(int arr[], int l, int r) {
    if(l < r) {
        int mid = (l + r)/2;
        mergeSortRecur(arr, l, mid);
        mergeSortRecur(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortRecur(arr, 0, n-1);
}


int main () {

    int arr[] = {5, 75, 17, 42, 2, 39, 23, 11, 55, 9};

    int n = sizeof(arr)/(sizeof(int));

    cout << "Array before sorting: "; 
    for(int i=0; i<n; i++) {
        cout << arr[i] << " \n"[i==n-1];
    }
    mergeSort(arr, n);
    cout << "Array after sorting: "; 
    for(int i=0; i<n; i++) {
        cout << arr[i] << " \n"[i==n-1];
    }
    return 0;
}