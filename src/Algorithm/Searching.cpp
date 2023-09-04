#include "../../include/Algorithm/Sorting.h"

int SearchElement(vector<int> arr, int num)
{
    int count_num =1;
    arr = SortArray(arr);
    if(num ==1)
    {
        return arr[arr.size()-1];
    }
    for(int i = arr.size()-1; i>=0; i--)
    {
        if(arr[i] != arr[i-1])
        {
            count_num ++;
            if(count_num == num)
            {
                return arr[i-1];
            }
        }
    }
    return -1;
}

int DifferentValuesInMultiplicationTable(vector<vector<int>> arr, int row, int col)
{
    int val = arr[row][col];
    int count = 0;
    for(int i =0; i<row; i++)
    {
        for (int j = 0; j < col; i++)
        {
            if(val != arr[i][j])
            {
                count++;
            }
        }
    }
    return count;
}

/// @brief Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
/// @param nums  The array of integers nums
/// @param target Target which must search
/// @return Indices of the two numbers such that they add up to target
vector<int> TwoSum(vector<int> &nums, int target)
{
    for(int i=0; i< nums.size()-1; i++)
    {
        for(int j= i+1; j< nums.size(); j++)
        {
            if(nums[i] + nums[j]== target)
            {
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>{};
}

/// @brief Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
/// @param x The non-negative integer
/// @return The square root of x rounded down to the nearest integer
int mySqrt(int x)
{
    if(x <= 1)
    {
        return x;
    }
    int left= 1, right= x;
    int result ;
    while(left<= right)
    {
        int mid= left + (right- left)/2;
        //Khi nay result se nam trong khoang (mid;x)
        if(mid <= x/mid)
        {
            left = mid +1;
            result = mid;
        }
        //khi nay result se nam trong khoang (left;mid)
        else
        {
            right = mid -1;
        }
    }
    return result;
}

/// @brief Valid Parentheses
/// @param str The string s containing just the characters '(', ')', '{', '}', '[' and ']
/// @return Determine if the input string is valid
bool isValid(string str)
{
    stack<char> stk;
    //Dinh nghia cac cap dau ngoac hop le
    map<char, char> key;
    key[')'] = '(';
    key['}'] = '{';
    key[']'] = '[';

    for(char s: str)
    {
        if(s == '(' || s== '{' || s== '[')
        {
            stk.push(s);
        }
        else if(s ==')' || s== '}' || s== ']')
        {
            //Neu roi vao TH ngoac dong de thoa man thi stack da ton tai ngoac mo.
            if(stk.empty() || stk.top() != key[s])
            {
                //Tuc la stack chua co ngoac mo.
                return false;
            }
            //tuc la truoc do da co dau ngoac mo nen thoa man va xoa di, xet truong hop khac
            stk.pop();
        }
    }
    return stk.empty();
}

/// @brief Best Time to Buy and Sell Stock
/// @param prices An array prices where prices[i] is the price of a given stock on the ith day
/// @return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
int MaxProfit(vector<int> &prices)
{
    int maxProfit= 0;
    int minPrice= prices[0];
    for(int price: prices)
    {
        minPrice = min(minPrice, price);
        int Profit = price - minPrice;
        maxProfit = max(maxProfit, Profit);
        // cout<<"minPrice: "<<minPrice<<"\nProfit: "<<Profit<<"\nmaxProfit: "<<maxProfit<<"\n"<<endl;
    }
    return maxProfit;
}


/// @brief Valid Palindrome
/// @param str A string 
/// @return True if it is a palindrome, or false otherwise.
bool isPalindrome(string str)
{
    string strLower="";
    for(char s: str )
    {
        s= tolower(s);
        if('a' <= s && s <= 'z')
        {
            strLower.push_back(s);
        }
    }
    for(int i=0; i<= strLower.length()/2; i++)
    {
        if(strLower[i] != strLower[strLower.length()-1-i])
        {
            return false;
        }
    }
    return true;
}

/// @brief Valid Anagram
/// @param s String s
/// @param t String t
/// @return True if t is an anagram of s, and false otherwise.
bool isAnagram(string s, string t) 
{
    if(s.size() != t.size())
    {
        false;
    }
    vector<int> s_arr(256, 0);
    vector<int> t_arr(256, 0);
    for(int i=0; i< s.size(); i++)
    {
        s_arr[s[i]] +=1;
        t_arr[t[i]] +=1;
    }
    for(int i= 'a'; i<= 'z'; i++)
    {
        if(s_arr[i] != t_arr[i])
        {
            return false;
        }
    }
    return true;
}

/// @brief Binary Search
/// @param nums The array of integers nums which is sorted in ascending order
/// @param target The target which want to search
/// @return The target's index. Otherwise, return -1
int BinarySearch(vector<int> &nums, int target)
{
    int left= 0;
    int right= nums.size()-1;
    while(left<= right)
    {
        int mid= left+ (right- left)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid]< target)
        {
            left= mid+1;
        }
        else{
            right = mid -1;
        }
    }
    return -1;
}

/// @brief Maximum Subarray
/// @param nums an integer array nums, find the subarray with the largest sum, 
/// @return its sum
int maxSubArray(vector<int>& nums)
{
    int maxSum= 0;
    int currentSum= 0;
    for(int i=0; i< nums.size(); i++)
    {
        currentSum = max(nums[i], nums[i]+ currentSum);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// int RemoveElement(vector<int> &nums, int val)
// {
//     int k= 0;
//     for(int i= 0; i< nums.size(); i++)
//     {
//         if(nums[i] != val)
//         {
//             cout<<"nums["<<i<<"]: "<<nums[i];
//             nums[k] = nums[i];
//              k++;
//         }
//     }
//     return k;
// }

/// @brief Climbing Stairs
/// @param n The steps reach the top
/// @return Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
int climbStairs(int n)
{
    if(n ==1 || n== 2)
    {
        return n;
    }
    vector<int> nums(n+1);
    nums[1] = 1;
    nums[2] = 2;
    for(int i= 3; i< n+1; i++)
    {
        nums[i] = nums[i-1] + nums[i-2];
    }
    return nums[n];
}

/// @brief Length of Last Word
/// @param s The string s consisting of words and spaces
/// @return the length of the last word in the string
int lengthOfLastWord(string s)
{
    int index= s.length()-1;
    while(index>=0 && s[index]== ' ')
    {
        s.pop_back();
        index--;
    }
    int count=0;
    for(int i= s.length()-1; i>=0; i--)
    {
        if(s[i]== ' ')
        {
            break;
        }
        count++;
    }
    return count;
}

/// @brief Missing Number
/// @param nums An array nums containing n distinct numbers in the range [0, n]
/// @return the only number in the range that is missing from the array
int missingNumber(vector<int>& nums)
{
    // if(nums.size() ==1)
    // {
    //     return nums[0]+1;
    // }
    int max= nums[0];
    int min= nums[0];
    int sumNums=0;
    for(int i=0; i< nums.size(); i++)
    {
        sumNums+= nums[i];
        if(nums[i] < min)
        {
            min = nums[i];
        }
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    if(min != 0)
    {
        return 0;
    }
    int sum=0;
    for(int i= min; i<= max; i++)
    {
        sum+=i;
    }
    int missNum= sum- sumNums;
    if(missNum == 0)
    {
        return max+1;
    }
    return missNum;
}

/// @brief Single Number
/// @param nums  A non-empty array of integers nums, every element appears twice except for one
/// @return That single one
int singleNumber(vector<int> &nums)
{
    //Su dung tinh chat cua phep XOR
    //0 XOR voi n =n
    //n XOR n =0
    int result =0;
    for(int elm: nums)
    {
        result ^= elm;
    }
    return result;
}

/// @brief Insert Interval
/// @param intervals  An array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
/// @param newInterval You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
/// @return intervals after the insertion.
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> result;
    int i=0;
    int n= intervals.size();
    //Xet cac phan tu end< start cua newInterval=> them phan tu vao result
    while(i< n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }
    //Xet cac phan tu end cua newInterval < start cua intervals thi update lai newval
    while (i<n && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] =min(newInterval[0], intervals[i][0]);
        newInterval[1] =max(newInterval[1], intervals[i][1]);
        i++; 
    }
    result.push_back(newInterval);
    while(i<n)
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) 
    {
        for (int coin : coins) {
            if (i >= coin) {
                cout<<"\nLan thu "<<i<<"\ncoin= "<<coin<<"\ndp= "<<dp[i]<<"\ndp[i-coin]+1= "<<dp[i-coin]+ 1<<endl;
                dp[i] = min(dp[i], dp[i - coin] + 1);
                cout<<"dp[i]= "<<dp[i]<<endl;
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}

/// @brief Palindrome Number
/// @param num Given an integer x
/// @return true if x is a palindrome and false otherwise
bool isPalindrome(int num)
{
    string numStr = to_string(num);
    int left = 0;
    int right = numStr.length() - 1;
    
    while (left < right) {
        if (numStr[left] != numStr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


/// @brief Majority Element
/// @param nums An array nums of size n
/// @return The majority element
int majorityElement(vector<int>& nums)
{
    int candidate= nums[0];
    int count =1;
    for(int i=1; i< nums.size(); i++)
    {
        if(candidate == nums[i])
        {
            count++;
        }
        else if (count > 0)
        {
            count--;
        }
        else{
            candidate = nums[i];
            count = 1;
        }
        cout<<"Lan thu "<<i<<"\nCandidate: "<<candidate<<"\ncount: "<<count<<"\n"<<endl;

    }
    return candidate;
}

