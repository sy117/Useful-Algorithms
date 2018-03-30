// Max Heap Implementation in C++

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

void max_heapify(int a[], int i)
{
	int l,r,largest;
	l = 2*i+1;
	r = 2*i+2;
	if(l < heap_size && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	
	if(r < heap_size && a[r] > a[largest])
	{
		largest = r;
	}
	
	if(largest != i)
	{
		swap(&a[i], &a[largest]);
		max_heapify(a, largest);
	}
}

void build_max_heap(int a[], int n)
{
	heap_size = n;
	int i = ceil(n/2);
	for(;i>=0;i--)
	{
		max_heapify(a, i);
	}
}

int extract_max(int a[])
{
	if(heap_size==0)
	{
		return -1;
	}
	int max_element = a[0];
	a[0] = a[heap_size-1];
	heap_size--;
	max_heapify(a, 0);
	return max_element;
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
	build_max_heap(arr,n);
	for(int i=0;i<n;i++)
	{
		int k = extract_max(arr);
		cout<<k<<" \n"[i==n-1];
	}
	return 0;
}
