#include<iostream>
using namespace std;

int main(){

    char c ;
    c = cin.get();
    int count1=0,count2=0,count3=0;
    while(c!='$'){
        if((int)c>=48 && (int)c<=57){
            count1++;
        }
        if((int)c >= 65 && (int)c <= 122){
            count2++;
        }
        if((int)c ==32 || (int)c==10 || (int)c == 9){
            count3++;
        }
      c = cin.get();  
    }
    cout<<count2<<" "<<count1<<" "<<count3;
  
}
