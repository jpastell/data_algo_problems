// #include <bits/stdc++.h>

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int l, int r);

// This function returns K'th smallest element in arr[l..r]
// using QuickSort based method. ASSUMPTION: ALL ELEMENTS IN
// ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int K)
{
	// If k is smaller than number of elements in array
	if (K > 0 && K <= r - l + 1) {

		// Partition the array around last element and get
		// position of pivot element in sorted array
		int pos = partition(arr, l, r);

		// If position is same as k
		if (pos - l == K - 1)
			return arr[pos];
		if (pos - l > K - 1) // If position is more, recur
							// for left subarray
			return kthSmallest(arr, l, pos - 1, K);

		// Else recur for right subarray
		return kthSmallest(arr, pos + 1, r,
						K - pos + l - 1);
	}

	// If k is more than number of elements in array
	return 1000;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Standard partition process of QuickSort(). It considers
// the last element as pivot and moves all smaller element
// to left of it and greater elements to right
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}

	swap(&arr[i], &arr[r]);
	return i;
}

void kLargest(int arr[], int n, int k) {
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; i++) {
        cout << " kLargest "<<arr[i] << ", ";
    }
}

// Driver's code
int main()
{
	int arr[] = { 1, 5, 1, 1, 6, 4 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 3;

	kLargest(arr,N,K);

	// Function call
	cout << "K'th smallest element is " << kthSmallest(arr, 0, N - 1, K);
	return 0;
}
