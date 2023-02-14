// 找到所有数组中消失的数字
// 给你一个含n个整数的数组nums，其中nums[i]在区间[1, n]内。
// 请你找出所有在[1, n]范围内没有出现的nums中的数字，并以数组的形式返回结果。
vector<int> findDisappearedNumbers(vector<int> nums) {
     int n = nums.size();
     for (int i = 0; i < n; i++) {
         int x = (nums[i]-1) % n;
         nums[x] += n;
     }

     vector<int> result;
     for (int i = 0; i < n; i++) {
         if (nums[i] <= n) {
             result.push_back(i+1);
         }
     }

     return result;
 }