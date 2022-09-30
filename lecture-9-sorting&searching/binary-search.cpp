/*input:
7 <- number of elements
1 3 7 9 11 12 45
1 <- number of elements to be searched
3 <- element to be searched

Output:
1*/
#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
   int start =0;
    int end = n-1;
    int index = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(input[mid]==val){
            index = mid;
            break;
        }
        if(input[mid]>val){
            end = mid-1;
        }
        if (input[mid]<val){
            start = mid +1;
        }
        
    }
    if(index!=-1){
        return index;
    }
    else return -1;
}
int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	
	delete [] input;
	return 0;
}