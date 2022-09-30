#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int i =1,j=1;
    while(i<=n){
        int space = 1;
        while(space<=n-i){
            cout<<" ";
            space++;
        }
        int j = 1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        j = i-1;
        while(j>=1){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  
}
