class Solution {
public:

    vector<vector<int>> threeSum(vector<int> nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int a = 0;
            
            for (a; a < nums.size() - 2; a++){
                if (a > 0 && nums[a] == nums[a-1]) continue;
                if (nums[a] > 0) break;
                int b = a + 1, c = nums.size() - 1;
                while(b < c){
                    int sum = nums[a] + nums [b] + nums[c];
                    
                    if (sum == 0){
                        ans.push_back({nums[a], nums[b], nums[c]});
                        while(b < c && nums[b] == nums[b+1]) b++;
                        while(b < c && nums[c] == nums[c-1]) c--;
                        b++;
                        c--;
                    }
                    else if (sum < 0){
                        b++;
                    }
                    else{
                        c--;
                    }
                }
            }
        return ans;
    }
};