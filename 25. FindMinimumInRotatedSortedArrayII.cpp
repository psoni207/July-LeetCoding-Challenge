class Solution {
    
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res;
        res = search(nums,0,n-1);
        
        return res;
        
    }
    
     int search(vector<int> &nums, int left, int right){
            if(left == right){ 
                return nums[left];
            }
            
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right]){
                return search(nums, mid+1, right);
            }else if(nums[mid] < nums[right] ){
                return search(nums,left, mid);
            }
         
            return search(nums, left, right-1);
            
        }
};