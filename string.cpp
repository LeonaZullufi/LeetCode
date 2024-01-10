#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Find Maximum Number of String Pairs
class String1 {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;

        for(int i=0; i<n-1; i++){
            string s=words[i];
            for(int j=i+1; j<n; j++){
                string t=words[j];
                reverse(t.begin(), t.end());
                if(t==s) cnt++;

            }
        }

        return cnt;
    }
};
//Goal Parser Interpretation
class String2 {
public:
    string interpret(string command) {
        string ans;
        for(int i=0;i<command.size();i++){
            if(command[i]=='G')
                ans.push_back('G');
            else if(command[i]=='('){
                if(command[i+1]==')'){
                    ans.push_back('o');
                }
                else{
                    ans.push_back('a');
                    ans.push_back('l');
                }
            }
        }
        return ans;
    }
};
//Split a String in Balanced Strings
class String3 {
public:
    int balancedStringSplit(string s) {

        int countR=0;
        int countL=0;
        int balanced_string=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
                countR++;
            else
                countL++;

            if(countR==countL)
            {
                balanced_string++;
                countR=0;
                countL=0;
            }
        }
        return balanced_string;


    }
};
//Check If Two String Arrays are Equivalent
class String4 {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string wrd1,wrd2;
        for (int i=0;i<word1.size();i++) {
            wrd1 = wrd1 + word1[i];
        }
        for (int i=0;i<word2.size();i++) {
            wrd2 = wrd2 + word2[i];
        }
        return wrd1 == wrd2;
    }
};
//Shuffle String
class String5 {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        for(int i=0; i<s.size(); i++)
            str[indices[i]] = s[i];
        return str;
    }
};



