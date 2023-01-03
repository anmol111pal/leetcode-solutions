#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string ans="";
        for(char ch: str) {
            if(ch >= 65 && ch <= 90)
                ch += 32;
            ans += ch;
        }
        return ans;
    }
    string capitalizeTitle(string title) {
        string word="", ans="";
        int len=title.length();

        for(int i=0; i<len; i++) {
            if(title[i] != ' ')
                word+=title[i];
            else {
                // word has been formed
                if(word.length() <= 2)
                    ans += toLowerCase(word);
                else {
                    // convert the first letter to uppercase
                    if(word[0] >= 97 && word[0] <= 122)
                        word[0]-=32;
                    ans += word[0];
                    ans += toLowerCase(word.substr(1)); // converting the rest to lowercase
                }
                ans += " "; // adding a space after each word
                word=""; // reset word
            }
        }

        // now the word will contain the last word
        if(word.length() <= 2)
            ans += toLowerCase(word);
        else {
            if(word[0] >= 97 && word[0] <= 122)
                word[0]-=32; // convert the first letter to uppercase
            ans += word[0];
            ans += toLowerCase(word.substr(1)); // converting the rest to lowercase
        }

        return ans;
    }
};