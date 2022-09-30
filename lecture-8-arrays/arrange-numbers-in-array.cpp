/*
input: 
1
6
Output: 1 3 5 6 4 2 */
#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
    int j = 0;
	int i = 0;
    
    while(j <= n){
        
        if( j % 2 != 0){
            arr[i] = j;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    j = n;
    while(j >= 1){
        
        if(j % 2 == 0){
            arr[i] = j;
            i++;
            j--;
        }
        else{
            j--;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int *arr = new int[n];
		arrange(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete [] arr;
	}

	
}