#include <iostream>
using namespace std;
int main()
{
    int n, i, j, num = 1, gap;
    cin>>n;
    gap = n - 1;
 
    for ( j = 1 ; j <= n ; j++ )
    {
        num = j;
        for ( i = 1 ; i <= gap ; i++ )
            cout << " ";
 
        gap --;
        for ( i = 1 ; i <= j ; i++ )
        {
            cout << num;
            num++;
        }
        num=num-2;
        
        for ( i = 1 ; i < j ; i++)
        {
            cout << num;
            num--;
        }
        cout << "\n";
    }
    return 0;
}