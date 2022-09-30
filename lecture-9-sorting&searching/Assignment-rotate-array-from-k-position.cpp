/*
Input:
1
7
1 2 3 4 5 6 7
2
output:
3 4 5 6 7 1 2*/
#include <iostream>
using namespace std;

void reverse(int *arr,int begin,int end){
    while(begin<end){
        int temp = arr[begin];
        arr[begin]=arr[end];
        arr[end]=temp;
        begin++;
        end--;
    }
}
void rotate(int *input, int d, int n)
{
    reverse(input,0,n);
    reverse(input,0,n-d);
    reverse(input,n-d,n);

}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}