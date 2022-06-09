class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cmp = INT_MIN,ans = -1;
        for(auto it:mp){
            if(cmp<it.second){
                cmp = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};
