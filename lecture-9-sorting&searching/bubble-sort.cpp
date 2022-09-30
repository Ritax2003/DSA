#include <iostream>
using namespace std;

/*
input:
1
7
2 13 4 1 3 6 28

output:
1 2 3 4 6 13 28*/
void bubbleSort(int *input, int size)
{
    int k = 0;
    while(k<size-1){
    for(int i =0;i<size-1;i++){
        if(input[i]>input[i+1]){
                int temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
        }
     }
    k++;
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

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}
}