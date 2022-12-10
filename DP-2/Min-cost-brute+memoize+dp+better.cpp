#include <iostream>
using namespace std;
#include <climits>

int minCOst_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}


int minCostPath_Better(int **input, int m, int n, int i, int j, int **ans) {
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	if(ans[i][j] != -1) {
		return ans[i][j];
	}

	int x = minCostPath_Better(input, m, n, i+1, j, ans);
	if(x < INT_MAX) {
		ans[i+1][j] = x;
	}
	int y = minCostPath_Better(input, m, n, i+1, j+1, ans);
	if(y < INT_MAX) {
		ans[i+1][j+1] = y;
	}
	int z = minCostPath_Better(input, m, n, i, j+1, ans);
	if(z < INT_MAX) {
		ans[i][j+1] = z;
	}

	ans[i][j] = min(x, min(y, z)) + input[i][j];
	return ans[i][j];
}



















int minCostPath_Better(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
		for(int j = 0; j < n; j++) {
			ans[i][j] = -1;
		}
	}
	return minCostPath_Better(input, m, n, 0, 0, ans);
}


int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCOst_DP(input, m, n) << endl;
	cout << minCostPath_Better(input, m, n) << endl;
	cout << minCostPath(input, m, n) << endl;
}