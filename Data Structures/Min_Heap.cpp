// Min Heap Implementation in C++

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int heap_size = N;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void min_heapify(int a[], int i)
{
	int l,r,smallest;
        // 0 based indexing
	l = 2*i+1;
	r = 2*i+2;
	if(l < heap_size && a[l] < a[i])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	
	if(r < heap_size && a[r] < a[smallest])
	{
		smallest = r;
	}
	
	if(smallest != i)
	{
		swap(&a[i], &a[smallest]);
		min_heapify(a,smallest);
	}
}

void build_min_heap(int a[], int n)
{
	heap_size = n;
	int i = ceil(n/2);
	for(;i>=0;i--)
	{
		min_heapify(a,i);
	}
}

int extract_min(int a[])
{
	if(heap_size==0)
	{
		return -1;
	}
	int min_element = a[0];
	a[0] = a[heap_size-1];
	heap_size--;
	min_heapify(a,0);
	return min_element;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	build_min_heap(arr,n);
	for(int i=0;i<n;i++)
	{
		int k = extract_min(arr);
		cout<<k<<" \n"[i==n-1];
	}
	return 0;
}
