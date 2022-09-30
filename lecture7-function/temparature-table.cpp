/*input: 
0 
100 
20
Output: 
0       -17
20      -6
40      4
60      15
80      26
100     37*/
#include<iostream>
using namespace std;
void printTable(int start, int end, int step) {
    int i = 0;
    float fah=0,cel=0;
    for(i=0;i<=((end-start)/step);i++){
        fah = start + (step*i);
        cel = ((fah - 32)/9)*5;
        cout<<(int)fah<<"	"<<(int)cel<<endl;
    }
    
}

int main(){
    int start, end, step;
    cin >> start >> end >> step;
  
    printTable(start, end, step);

}