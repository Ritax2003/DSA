/* input: 
4 
3 9 0 9

output: 3*/
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int max = INT_MIN, secondMax = INT_MIN;
    int num;
    int count = 1;
    while(count <= n) {
        cin >> num;
        if(num > max) { 
            secondMax = max;
            max = num;
        } 
        else if(num > secondMax && num != max) {
            secondMax = num;
        }
        count++;
    }
    cout << secondMax << endl;
}