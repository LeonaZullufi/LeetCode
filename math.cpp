#include <string>
#include <vector>
#include <algorithm>
using namespace std;
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
