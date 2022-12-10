/*
Code: Knapsack (Memoization and DP)

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/
#include <cstring>
#include <iostream>
using namespace std;

int knapsack(int* w, int* v, int n, int m) {
	int arr[n+1][m+1];
	int i ,j;
	for(int i =0;i<n+1;i++){
		for(int j =0;j<m+1;j++){
			if(i==0||j==0){
				arr[i][j]=0;
			}
		}
	}
	for(i=1;i<n+1;i++){
		for(j=1;j<m+1;j++){
			if(w[i-1]<=j){
				int a = v[i-1]+arr[i-1][j-w[i-1]];
				int b = arr[i-1][j];
				arr[i][j]=max(a,b);
            } 
		else {
                arr[i][j] = arr[i - 1][j];
         }
     }
	}
	return arr[n][m];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}