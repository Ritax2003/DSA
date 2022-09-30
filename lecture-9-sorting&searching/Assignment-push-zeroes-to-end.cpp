/*Input:
2
5
0 3 0 2 0
Output:
3 2 0 0 0 */
#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
    int i =0;
    int count =0;
   for(i=0;i<size;i++){
       if(input[i]!=0){
           input[count]=input[i];
           count++;
       }
       
   }
    while(count<size){
        input[count]=0;
        count++;
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

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}