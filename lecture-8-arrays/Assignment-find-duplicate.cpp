/*
input:
1
9
0 7 2 5 4 7 1 3 6
Output: 7*/
#include <iostream>
using namespace std;
int duplicateNumber(int *arr, int size)
{
    int check[size]={0};
    for(int i=0;i<size;i++){
        int index=0;
        index= arr[i];
        check[index]++;
    }
    for(int i=0;i<size;i++){
        if(check[i]>1){
            return i;
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << duplicateNumber(input, size) << endl;
	}

	return 0;
}