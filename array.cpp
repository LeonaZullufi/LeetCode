#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
//Maximum Number of Words Found in Sentences
class Array1 {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=1;
        int ans=0;
        for(int i=0;i<sentences.size();i++){
            string sentence=sentences[i];
            for(int j=0;j<sentence.size();j++){
                if(sentence[j]==' '){
                    count++;

                }


            }
            ans=max(ans,count);
            count=1;
        }
        return ans;
    }
};
//Count the Number of Consistent Strings
class Array2 {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int count = 0;

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            bool consistent = true;

            for (int j = 0; j < word.size(); ++j) {
                if (allowedSet.find(word[j]) == allowedSet.end()) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) {
                count++;
            }
        }

        return count;
    }
};
//Left and Right Sum Differences
class Array3 {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int lsum = 0, rsum = 0;
        for(int i = 0; i < nums.size(); ++i ) rsum += nums[i];
        for(int i = 0; i < nums.size(); ++i){
            rsum -= nums[i];
            ans.push_back(abs(lsum - rsum));
            lsum += nums[i];
        }
        return ans;
    }
};
//Decompress Run-Length Encoded List
class Array4 {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];


            for (int j = 0; j < freq; ++j) {
                result.push_back(val);
            }
        }

        return result;
    }
};
//Count Items Matching a Rule
class Array5 {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int n=items.size();
        int count=0;
        for (int i = 0; i < n; i++)
        {
            if (ruleKey == "type")
            {
                if (ruleValue == items[i][0])
                {
                    count++;
                }
            }
            else if (ruleKey == "color")
            {
                if (ruleValue == items[i][1])
                {
                    count++;
                }
            }
            else if (ruleKey == "name")
            {
                if (ruleValue == items[i][2])
                {
                    count++;
                }
            }
        }
        return count;


    }
};