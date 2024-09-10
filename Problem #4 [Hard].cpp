// This problem was asked by Stripe.

// Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

// You can modify the input array in-place.
#include<bits/stdc++.h>
using namespace std;
// 本题较难的是如何使用O(N)时间复杂度和O(1)空间复杂度。需要明确的是答案存在于[1, len(A)+1]区间。
// 1.先将数组进行排序或二分，然后在区间内遍历；时间复杂度主来自排序或二分，O(NlogN)。空间为O(1)。
// 2.先数组转化成哈希表，然后区间内遍历；时间复杂度为O(N)。空间为O(N)。
// 3.原地哈希 + 区间内遍历可满足题目要求。

int firstMissingPositive_v1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[tmp-1] = tmp;
            }
        }
        for(int i = 1; i <= n ; i++){
            if(nums[i-1] != i) return i;
        }
        return n+1;
        
}//各就各位
int firstMissingPositive_v2(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) nums[i] = 0; // 我们并不关心负数和0.
        }
        for(int i = 0;i < n; i++){
            int idx = abs(nums[i]) - 1;
            if(idx >=0 and idx < n){
                if(nums[idx] > 0) nums[idx] *= -1; //找到的话就为负数
                else if(nums[idx] == 0) nums[idx] = - (n+2);
            }
        }
        for(int i = 1; i <= n ; i++){
            if(nums[i-1] >=0) return i;//所以最后所有的非负数为缺失区间中的值
        }
        return n+1;
        
}//无交换成本，只需要符号。



