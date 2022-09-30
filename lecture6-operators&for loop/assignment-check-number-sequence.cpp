#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    int count = 2, current;
    bool isDec = true; 
    while(count <= n) {
        cin >> current;
        if(current == prev) {
            cout << "false";
            return 0;
        } 
        count++;
        if(current < prev) { 
            if(isDec == false) {
                cout << "false";
                return 0;
            }
        }
        else {
            if(isDec == true) {
                isDec = false;
            }
        }
        prev = current;
    }
    cout << "true";
}