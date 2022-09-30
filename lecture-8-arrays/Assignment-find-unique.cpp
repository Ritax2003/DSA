/*
input:
1
7
2 3 1 6 3 6 2
output: 1 */
#include <iostream>
using namespace std;
// solution 1 : 2 for loops
int findUnique(int *arr, int size)
{   int i =0;
 if(size==1){
     return arr[0];
 }
 else{
    int check[size]={0};
    for(i =0;i<size;i++){
        int index=0;
        index = arr[i];
        check[index]++;
    }
    for(i = 0;i<size;i++){
        if(check[i]==1){
            return i;
            break;
        }
   
    }
 }
}
/* Solution 2: 1 for loop
int findUnique(int *arr, int size)
{
    for(int i =0;i<size;i++){
        int j = 0;
        for(j=0;j<size;j++){
            if(i!=j){
                if(arr[i] == arr[j]){
                    break;
            }
        }
    }
        if (j==size){
     return arr[i];
        }
    }
    return -1;
}
*/
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

		cout << findUnique(input, size) << endl;
	}

	return 0;
}