/*
Given the number 'n', find out and return the number of digits present in a number recursively.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
*/#include<iostream>
using namespace std;

int count(int n){
static int c=0;
    if(n>0){
        c++;
        count(n/10);
    }
    else return c;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


