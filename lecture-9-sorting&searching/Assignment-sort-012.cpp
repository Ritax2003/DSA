/*
input:
1
7
0 1 2 0 2 0 1
Output: 0 0 0 1 1 2 2*/
#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *A, int n) {
    int k = n - 1; 
    int i = 0;
    for (; i < n; ++i) {
        if (A[i] != 0) {
            break;
        }
    }
    int j = i;
    for (; i <= k; ++i) {
        if (A[i] == 0) {
            swap(A[j++], A[i]); 
        }
        else if (A[i] == 2) {
            swap(A[i--], A[k--]); 
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}