/*
input:
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
output: 
2 4 3
10*/
#include <iostream>
#include <algorithm>
using namespace std;
void intersection(int input1[], int input2[], int size1, int size2)
{
    int i = 0,j =0;
    int input3[1000000]={0};
    for(i=0;i<size1;i++){
        for(j=0;j<size2;j++){
            if(input1[i]==input2[j] && input2[j]!=input3[j]){
                cout<<input2[j]<<" ";
             input3[j] = input2[j];
                break;
            }
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}