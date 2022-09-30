/*
Check AB

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/
#include <iostream>
using namespace std;
bool checkAB(char input[]) {
	if(input[0]!='a'){
        return false;
    }
    if(input[0]=='a'){
        if(input[1]=='a'){
            return checkAB(input+1);
        }
        if(input[1]=='a'||input[1]=='\0'){
            return true;
        }
        if(input[1]=='b'&& input[2]=='b'){
            if(input[3]=='a'|| input[3]=='\0'){
                return true;
            }
        }
    }
    else return false;
    checkAB(input+1);
   

}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
