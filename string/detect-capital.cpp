/*
    We define the usage of capitals in a word to be right when one of the following cases holds:

    - All letters in this word are capitals, like "USA".
    - All letters in this word are not capitals, like "leetcode".
    - Only the first letter in this word is capital, like "Google".

    Given a string word, return true if the usage of capitals in it is right.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // to check if the word [1... len-1] contains an uppercase char
    bool checkRestWord(string s) {
        int i=1, len=s.length();
        // checking if the rest of the letters are uppercase
        while(i < len) {
            if(s[i] >= 65 && s[i] <= 90) // uppercase found
                return true;
            else
                i++;
        }
        return false;
    }

    string toUpperCase(string str) {
        string ans="";
        for(char ch: str) {
            if(ch >= 97 && ch <= 122)
                ch-=32;
            ans+=ch;
        }
        return ans;
    }
    string toLowerCase(string str) {
        string ans="";
        for(char ch: str) {
            if(ch >= 65 && ch <= 90)
                ch+=32;
            ans+=ch;
        }
        return ans;
    }
    bool detectCapitalUse(string word) {
      if(word == toUpperCase(word) || word == toLowerCase(word))
        return true;

    bool ans=checkRestWord(word);

      if(word[0] >= 65 && word[0] <= 90) { // first char is uppercase
        if(ans) // uppercase found after 0'th index
            return false;
        else
            return true;
      }
      else { // first char is lowercase
          if(ans) // no uppercase found after 0'th index
            return false;
          else
            return true;
      }
    }
};