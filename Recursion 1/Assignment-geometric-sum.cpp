/*
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500

1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
*/#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int pow(int n,int m){
    int r=1;
    while(m>0){
    r = r*n;
    m--;
    }
    return r;
}
double geometricSum(int k) {
   if(k==0){
       return 1;
   }
    double ans = (1/(double)pow(2,k))+geometricSum(k-1);
    return ans;
}


int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
