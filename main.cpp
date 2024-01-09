#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>
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
                if(t==s && s[0]!=s[1]) cnt++;

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
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G')
                ans.push_back('G');
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans.push_back('o');
                } else {
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
//Split a String in Balanced Strings
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
//Largest Local Values in a Matrix
class Matrix1
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>> res(n-2, vector<int> (n-2));


        for(int i=1; i<=n-2; i++)
        {
            for(int j=1; j<=n-2; j++)
            {
                int maxi=0;
                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi = max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});

                res[i-1][j-1] = maxi;
            }
        }
        return res;
    }
};
//Flipping an Image
class Matrix2 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        for(int i=0;i<m;i++){
            reverse(image[i].begin(),image[i].end());
        }
        int n=image[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]==0){
                    image[i][j]=1;
                }else{
                    image[i][j]=0;
                }
            }
        }
        return image;
    }
};
//Delete Greatest Value in Each Row
class Matrix3 {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
        int  row =g.size();
        int col = g[0].size();
        int sum=0;
        int max=-1;
        for(int i=0; i<row; i++){
            sort(g[i].begin(),g[i].end());
        }
        for(int i=0; i<col; i++){ max=0;
            for(int j=0; j<row; j++){
                if(max<g[j][i]){
                    max=g[j][i];}
            }
            sum+=max;
        }
        return sum;
    }
};
// Count Negative Numbers in a Sorted Matrix
class Matrix4 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }
        return count;
    }
};
//Row With Maximum Ones
class Matrix5 {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        vector<int> res{-1, -1};
        for(int i = 0; i < mat.size(); ++i){
            int one = count(mat[i].begin(), mat[i].end(), 1);
            if(one > res[1])
                res = {i, one};
        }
        return res;
    }
};
//Minimum Sum of Four Digit Number After Splitting Digits
class Math1 {
public:
    int minimumSum(int num) {
        string x=to_string(num);
        sort(x.begin(), x.end());
        swap(x[2], x[1]);
        return stoi(x.substr(0, 2)) + stoi(x.substr(2, 2));
    }
};
//Number of Steps to Reduce a Number to Zero
class Math2 {
public:
    int numberOfSteps(int num) {
        int a=0,b=0;
        while (num){
            a+=num%2;
            b++;
            num/=2;
        }
        return (a+b>0?a+b-1:0);
    }
};
//Sum Multiples
class Math3 {
public:
    int sumOfMultiples(int n) {
        int S=0;
        for(int i=0;i<=n;i++){
            if(i%3==0 || i%5==0 || i%7==0){
                S=S+i;
            }
        }
        return S;
    }
};
//Count the Digits That Divide a Number
class Math4 {
public:
    int countDigits(int num) {
        int a = num, ans = 0;
        while(a) {
            if(num % (a % 10) == 0) ans++;
            a /= 10;
        }
        return ans;
    }
};
//Sum of All Odd Length Subarrays
class Math5 {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int nTimes = ((i+1)*(n-i)+1)/2;
            ans+=nTimes*arr[i];
        }
        return ans;
    }
};
void Array(int n){
    switch(n){
        case 1:{
            Array1 arrayObject1;
            cout<<"You have chosen: Maximum Number of Words Found in Sentences\n";
            cout<<"Enter sentences (separated by Enter, type 'end' to finish input):\n";
            vector<string> sentences;
            string inputSentence;
            while (true) {
              getline(cin, inputSentence);

                if (inputSentence == "end") {
                    break;
                }
                sentences.push_back(inputSentence);
            }
            int result = arrayObject1.mostWordsFound(sentences);
            cout << "Maximum words found in a sentence: " << result << endl;
        } break;
        case 2:{
            Array2 arrayObject2;
            string allowed;
            vector<string> words;
            string inputWord;
            cout<<"You have chosen: Count the Number of Consistent Strings\n";
            cout << "Enter a string: ";
            cin >> allowed;
            cout << "Enter words (type 'end' to finish input):\n";
            while (true) {
                std::cin >> inputWord;

                if (inputWord == "end") {
                    break;
                }

                words.push_back(inputWord);
            }
            int result = arrayObject2.countConsistentStrings(allowed, words);
            cout << "Count of consistent strings: " << result << endl;

        }break;
        case 3: {
            Array3 arrayObject3;
            vector<int> nums;
            int inputNumber;
            cout<<"You have chosen: Left and Right Sum Differences\n";
            cout << "Enter numbers for the vector (type '0' to finish input):\n";
            while (true) {
                std::cin >> inputNumber;

                if (inputNumber == 0) {
                    break;
                }

                nums.push_back(inputNumber);
            }
            vector<int> result = arrayObject3.leftRightDifference(nums);
            cout << "Resulting vector after left-right difference: ";
            for (int i=0;i<result.size();i++) {
               cout << result[i] << " \n";
            }
        }break;
        case 4:{
            Array4 arrayObject4;
            vector<int> nums;
            int inputNumber;
            cout<<"You have chosen: Decompress Run-Length Encoded List\n";
            cout << "Enter numbers for the vector (type '0' to finish input):\n";
            while (true) {
               cin >> inputNumber;

                if (inputNumber == 0) {
                    break;
                }

                nums.push_back(inputNumber);
            }
            vector<int> result = arrayObject4.decompressRLElist(nums);
            cout << "Resulting decompressed vector: ";
            for (int i=0;i<result.size();i++) {
                cout << result[i] << " \n";
            }
        }break;
        case 5:{
            Array5 arrayObject5;
            string type, color, name;
            vector<vector<string>> items;
            cout<<"You have chosen: Count Items Matching a Rule\n";
            cout << "Enter items (type 'end' to finish input):\n";
            while (true) {
                cout << "Type: ";
                cin >> type;

                if (type == "end") {
                    break;
                }

                cout << "Color: ";
                cin >> color;

                cout << "Name: ";
                cin >> name;

                items.push_back({type, color, name});
            }
            cout << "Enter rule key (type/color/name): ";
            string ruleKey;
            cin >> ruleKey;
            cout << "Enter rule value: ";
            string ruleValue;
            cin >> ruleValue;
            int result = arrayObject5.countMatches(items, ruleKey, ruleValue);
            cout << "Count of matches: " << result << endl;



        }break;
        default:
            cout<<"End of the program";

    }
}
void String(int n ){
    switch(n) {
        case 1 : {
            String1 stringObject1;
            vector<string> words;
            string inputWord;
            cout<<"You have chosen: Find Maximum Number of String Pairs\n";
            cout << "Enter words (type 'end' to finish input):\n";
            while (true) {
                cin >> inputWord;

                if (inputWord == "end") {
                    break;
                }

                words.push_back(inputWord);
            }
            int result = stringObject1.maximumNumberOfStringPairs(words);

            cout << "Maximum number of string pairs: " << result << endl;

        }
            break;
        case 2:{
                String2 stringObject2;
                string command;
                cout<<"You have chosen: Goal Parser Interpretation\n";
                cout << "Enter command string: (command consists of \"G\", \"()\", and/or \"(al)\" in some order.)";
                cin >> command;
                string result = stringObject2.interpret(command);
                cout << "Interpreted string: " << result << endl;
                }break;
        case 3:{
            String3 stringObject3;
            cout<<"You have chosen: Split a String in Balanced Strings\n";
            cout << "Enter a string: ";
            string s;
            cin >> s;
            int result = stringObject3.balancedStringSplit(s);
            cout << "Number of balanced string splits: " << result <<endl;

                }break;
        case 4:{
            String4 stringObject4;
            cout<<"You have chosen: Split a String in Balanced Strings\n";
            cout << "Enter words for vector word1 (type 'end' to finish input):\n";
            vector<string> word1;
            string inputWord1;

            while (true) {
                cin >> inputWord1;

                if (inputWord1 == "end") {
                    break;
                }

                word1.push_back(inputWord1);
            }
            cout << "Enter words for vector word2 (type 'end' to finish input):\n";
            vector<string> word2;
            string inputWord2;

            while (true) {
                cin >> inputWord2;

                if (inputWord2 == "end") {
                    break;
                }

                word2.push_back(inputWord2);
            }
            bool result = stringObject4.arrayStringsAreEqual(word1, word2);
            cout << "Are the arrays of strings equal? " << (result ? "Yes" : "No") << endl;

                }break;
        case 5:{
            String5 stringObject5;
            string s;
            vector<int> indices;
            int inputIndex;
            cout<<"You have chosen: Shuffle String\n";
            cout << "Enter a string: ";
            cin >> s;
            cout << "Enter indices (type '0' to finish input):\n";
            while (true) {
                cin >> inputIndex;
                if (inputIndex == 0) {
                    break;
                }
                indices.push_back(inputIndex);
            }
            string result = stringObject5.restoreString(s, indices);
            cout << "Restored string: " << result << endl;
        }break;
        default:
            cout<<"End of the program";
    }
};
    void Matrix(int n){
        switch(n){
            case 1:{
                Matrix1 matrixObject1;
                vector<vector<int>> grid;
                int inputElement;

                cout << "Enter matrix elements (type '0' to finish input):\n";
                while (true) {
                    vector<int> row;   cout<<"You have chosen: Largest Local Values in a Matrix\n";
                    while (cin >> inputElement && inputElement != 0) {
                        row.push_back(inputElement);
                    }
                    if (row.empty()) {
                        break;
                    }
                    grid.push_back(row);
                }
                vector<vector<int>> result = matrixObject1.largestLocal(grid);
                cout << "Resulting largest local matrix:\n";
                for (const auto& row : result) {
                    for (int element : row) {
                      cout << element << " ";
                    }
                   cout << "\n";
                }

            }break;
            case 2:{
                Matrix2 matrixObject2;
                vector<vector<int>> image;
                int inputElement;
                cout<<"You have chosen: Flipping an Image\n";
                cout << "Enter image matrix elements (type '0' to finish input):\n";
                while (true) {
                    vector<int> row;
                    while (cin >> inputElement && inputElement != 0) {
                        row.push_back(inputElement);
                    }
                    if (row.empty()) {
                        break;
                    }
                    image.push_back(row);
                }
                vector<vector<int>> result = matrixObject2.flipAndInvertImage(image);
                cout << "Resulting flipped and inverted image matrix:\n";
                for (int i=0;i<result.size();i++) {
                    for (int j=0; j<result[i].size();j++) {
                        cout << result[i][j]<< " ";
                    }
                    cout << "\n";
                }
            }break;
            case 3:{
                Matrix3 matrixObject3;
                vector<vector<int>> g;
                int inputElement;
                cout<<"You have chosen: Delete Greatest Value in Each Row\n";
                cout << "Enter matrix elements (type '0' to finish input):\n";
                while (true) {
                    vector<int> row;
                    while (cin >> inputElement && inputElement != 0) {
                        row.push_back(inputElement);
                    }
                    if (row.empty()) {
                        break;
                    }
                    g.push_back(row);
                }
                int result = matrixObject3.deleteGreatestValue(g);
                cout << "Resulting sum after deleting greatest values: " << result <<endl;

            }break;
            case 4:{
                Matrix4 matrixObject4;
                vector<vector<int>> grid;
                int inputElement;
                cout<<"You have chosen: Count Negative Numbers in a Sorted Matrix\n";
                cout << "Enter matrix elements (type '0' to finish input):\n";
                while (true) {
                    vector<int> row;
                    while (cin >> inputElement && inputElement != 0) {
                        row.push_back(inputElement);
                    }
                    if (row.empty()) {
                        break;
                    }
                    grid.push_back(row);
                }
                int result = matrixObject4.countNegatives(grid);
                cout << "Number of negative elements in the matrix: " << result << endl;

            }break;
            case 5:{
                Matrix5 matrixObject5;
                vector<vector<int>> mat;
                int inputElement;
                cout<<"You have chosen: Row With Maximum Ones\n";
                cout << "Enter matrix elements (type '0' to finish input):\n";
                while (true) {
                   vector<int> row;
                    while (cin >> inputElement && inputElement != 0) {
                        row.push_back(inputElement);
                    }
                    if (row.empty()) {
                        break;
                    }
                    mat.push_back(row);
                }
                vector<int> result = matrixObject5.rowAndMaximumOnes(mat);
                if (result[0] != -1) {
                    cout << "Row with the maximum number of ones: " << result[0] << "\n";
                    cout << "Number of ones in that row: " << result[1] <<endl;
                } else {
                    cout << "Matrix is empty." <<endl;
                }
            }break;
            default:
                cout<<"End of the program";
        }
    };
void Math(int n){
    switch(n){
        case 1:{
            Math1 mathObject1;
            int num;
            cout<<"You have chosen: Minimum Sum of Four Digit Number After Splitting Digits\n";
            cout << "Enter a four-digit number: ";
            cin >> num;
            int result = mathObject1.minimumSum(num);
            cout << "Minimum sum of two-digit numbers obtained from rearranging digits: " << result << endl;
        }break;
        case 2:{
            Math2 mathObject2;
            int num;
            cout<<"You have chosen: Number of Steps to Reduce a Number to Zero\n";
            cout << "Enter a non-negative integer: ";
            cin >> num;
            int result = mathObject2.numberOfSteps(num);
            cout << "Number of steps to reduce the number to zero: " << result << endl;
        }break;
        case 3:{
            Math3 mathObject3;
            int n;
            cout<<"You have chosen: Sum Multiples\n";
            cout << "Enter a positive integer: ";
            cin >> n;
            int result = mathObject3.sumOfMultiples(n);
            cout << "Sum of multiples of 3, 5, and 7 up to " << n << ": " << result <<endl;

        }break;
        case 4:{
            Math4 mathObject4;
            int num;
            cout<<"You have chosen: Count the Digits That Divide a Number\n";
            cout << "Enter a positive integer: ";
            cin >> num;
            int result = mathObject4.countDigits(num);
            cout << "Count of digits that divide the number evenly: " << result << endl;

        }break;
        case 5:{
            Math5 mathObject5;
            vector<int> arr;
            int inputElement;
            cout<<"You have chosen: Sum of All Odd Length Subarrays\n";
            cout << "Enter array elements (type '0' to finish input):\n";
            while (true) {
                cin >> inputElement;
                if (inputElement == 0) {
                    break;
                }
                arr.push_back(inputElement);
            }
            int result = mathObject5.sumOddLengthSubarrays(arr);
            cout << "Sum of subarrays with odd length: " << result << endl;
            }break;
        default:
            cout<<"End of the program";
    }
}

int main(){
    int choose;
    int problem;
    cout<<"Hello! Please choose a number from 1 to 4 for the fields you want: (Array(1), String(2), Matrix(3), Math(4)). If you want to exit the program, press 0.";
    cin>>choose;

        switch(choose){
            case 1: cout<<"Enter a number from 1 to 5 to choose a random task from the Array field.If you want to exit the program, press 0.";
                    cin>>problem;
                    Array(problem);
            case 2: cout<<"Enter a number from 1 to 5 to choose a random task from the String field.If you want to exit the program, press 0.";
                cin>>problem;
                String(problem);
            case 3: cout<<"Enter a number from 1 to 5 to choose a random task from the Matrix field.If you want to exit the program, press 0.";
                cin>>problem;
                Array(problem);
            case 4: cout<<"Enter a number from 1 to 5 to choose a random task from the Math field.If you want to exit the program, press 0.";
                cin>>problem;
                Math(problem);
            default:
                cout<<"End of the program";




        }

    return 0;
}
