
/* 
input:
1
6
9 3 6 12 4 32
output: 3 9 12 6 32 4 */
#include <iostream>
using namespace std;
void swapAlternate(int *arr, int size)
{
    int i =0;
    int j,temp;
    while(i<size-1){
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        i = i+2;
        
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
		swapAlternate(arr, size);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete [] arr;
	}
}