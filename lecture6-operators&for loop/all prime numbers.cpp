#include <iostream>
using namespace std;

int main(){
int n;
    cin>>n;
    int i,j;
    for(i=2;i<=n;i++){
        int count = 0;
        for(j = 1;j<=i;j++){
            if(i%j==0){
                count++;
                
            }
        }
        if(count==2){
            cout<<i<<endl;
        }
    }
   
}
