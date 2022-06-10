class Solution {
public:
    
    int merge(vector<int> &nums,int low,int mid,int high){
        int j=mid+1,c = 0;
        for(int i=low;i<=mid;++i){
            while(j<=high && nums[i] >(long long) 2*nums[j]){
                j++;
            }
            c+=j-mid-1;
        }
        vector<int> temp ;
        int ll = low,rr = mid+1;
        while(ll<=mid and rr<=high){
            if(nums[ll] <= nums[rr]){
                temp.push_back(nums[ll++]);
            }else{
                temp.push_back(nums[rr++]);
            }
        }
        while(ll <=mid){
            temp.push_back(nums[ll++]);
        }
        while(rr<=high){
            temp.push_back(nums[rr++]);
        }
        for(int i =low;i<=high;++i){
            nums[i] = temp[i-low];
        }
        
        return c;
    }
    
    int mergeSort(vector<int> &nums,int left,int right){
        if(left == right)return 0;
        int mid = (left+right)/2;
        int inv = mergeSort(nums,left,mid);
        inv+=mergeSort(nums,mid+1,right);
        inv+=merge(nums,left,mid,right);
        
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);   
    }
};
