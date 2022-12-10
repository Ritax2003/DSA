/*
Palindrome Pair
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    string reverse(string word){
        string rev="";
        for(int i =word.size()-1;i>=0;i--){
            rev=rev+word[i];
        }
        return rev;
    }

    /*..................... Palindrome Pair................... */
bool isPalindromePair(vector<string>words){
        if(words.size()==0)
            return false;
        for(int i =0;i<words.size();i++){
            this->add(reverse(words[i]));
        }
        return isPalindromePair(this->root,words);
    }
    bool isPalindromePair(TrieNode *root,vector<string> words) {
        if(words.size()==0||root==NULL)
            return false;
        for(int i =0;i<words.size();i++){
            if(doespairexistfor(root,words[i],0)){
                return true;
            }
        }
        return false;
    }
    
    
    bool doespairexistfor(TrieNode *root,string word,int startindex){
        if(word.length()==0)
            return true;
        if(startindex==word.length()){
            if(root->isTerminal)
                return true;
            return checkremainingbranchesintrie(root,"");
        }
        int charindx = word[startindex]-'a';
        TrieNode *child =root->children[charindx];
        if(child==NULL){
            if(root->isTerminal){
                return checkwordforpallindrome(word.substr(startindex));
            }
            return false;
        }
        return doespairexistfor(child,word,startindex+1);
    }
    bool checkremainingbranchesintrie(TrieNode *root,string word){
        if(root->isTerminal){
            if(checkwordforpallindrome(word)){
                return true;
            }
        }
        for(int i =0;i<20;i++){
            TrieNode *child = root->children[i];
            if(child==NULL){
                continue;
            }
            string fwd = word+child->data;
            if(checkremainingbranchesintrie(child,fwd))
                return true;
        }
        return false;
    }
    bool checkwordforpallindrome(string word){
        int startindx = 0;
        int endindx = word.length()-1;
        while(startindx<endindx){
            if(word[startindx]!=word[endindx])
                return false;
            startindx+=1;
            endindx-=1;
        }
        return true;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}