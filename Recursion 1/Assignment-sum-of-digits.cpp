/*
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
*/#include <iostream>
using namespace std;
int sumOfDigits(int n) {
    int r=0;
    if(n>0){
        r=n%10;
        return r+sumOfDigits(n/10);
    }
    return r;

}



int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
