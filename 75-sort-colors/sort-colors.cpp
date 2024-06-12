class Solution {
public:
    void sortColors(vector<int>& nums) {
        int w=0,b=0,r=0;
        for(int i=0 ; i< nums.size(); i++)
        {
            if(nums[i]==0){
                r++;
            }
            else if(nums[i]==1){
                w++;
            }
            else if(nums[i]==2){
                b++;
            }
        }   
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(r>0){
                nums[i]=0;
                r--;
            }
            else  if(w>0){
                nums[i]=1;
                w--;
            }
            else if ( b > 0){
                nums[i]=2;
                b--;
            }
        }
        
    }
};