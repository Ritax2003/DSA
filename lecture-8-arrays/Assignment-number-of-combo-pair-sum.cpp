/*
input:
1
9
1 3 6 2 5 4 3 2 4
7
output:
7*/
#include <iostream>
using namespace std;

int pairSum(int *input, int size, int x)
{
	int i = 0,j=0;
    int count = 0;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
                if(input[i]+input[j]==x){
                        count++;
                }
                }
                
        }
    return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}