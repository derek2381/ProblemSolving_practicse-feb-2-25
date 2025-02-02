// ProblemLink
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/



// Source Code

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> mod;
        int n = nums.size();
        int i = 0,flag = 0;
        queue<int> q;

        for(i = 0;i < n;i++){
            if(flag == 1){
                mod.push_back(nums[i]);
            }else{
                if(!q.empty() && nums[i] < q.back()){
                    mod.push_back(nums[i]);
                    flag = 1;
                }else{
                    q.push(nums[i]);
                }
            }
        }
        while(!q.empty()){
            mod.push_back(q.front());
            q.pop();
        }

        sort(nums.begin(), nums.end());

        for(int i = 0;i < n;i++){
            if(nums[i] != mod[i]){
                return false;
            }
        }
        

        return true;

    }
};