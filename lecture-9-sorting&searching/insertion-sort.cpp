/*
Input:
1
7
2 13 4 1 3 6 28
Output:
1 2 3 4 6 13 28*/
#include <iostream>
using namespace std;

void insertionSort(int *input, int size)
{
    for(int i=1;i<size;i++){
        int current=input[i];
        int j;
        for( j = i-1; j >= 0;j--){
            if(current < input[j]){
                input[j+1]=input[j];    
            }
            else{
                break;
            }
        }
        input[j+1]=current;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		insertionSort(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}