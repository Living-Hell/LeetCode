//M1
//Binary Search
//Faster than 58.67% (15ms)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0, end = n-1;
        int lind = -1, rind = -1;

        //For left index
        while(start<=end){

            //Set the value of mid according to start and end index
            int mid = start + (end - start)/2;

            //If target element found, update the left index and 
            //Update the end pointer to search for the target element in the left subarray (if any)
            if(nums[mid] == target){
                lind = mid;
                end = mid-1;
            }

            else if(target > nums[mid])
                start = mid + 1;

            else
                end = mid-1;              

        }

        start = 0; end = n-1;

        //For right index
        while(start<=end){

            //Set the value of mid according to start and end index
            int mid = start + (end - start)/2;

            //If target element found, update the right index and 
            //Update the start pointer to search for the target element in the right subarray (if any)
            if(nums[mid] == target){
                rind = mid;
                start = mid+1;
            }

            //if target is greater than mid element, shift the start pointer to next of mid and search in the right subarray
            else if(target > nums[mid])
                start = mid + 1;

            //if target is less than mid element, shift the end pointer to previous of mid and search in the left subarray
            else
                end = mid-1;              

        }

        //return left index and right index of the target with default value -1 if target value not in the array
        return {lind,rind};

    }
};

//M2
//Counting the frequency and last index
//Faster than 65.92% (13ms)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
		//Take a counter to count the no. of elements as target in array and lindex to store the last index
		//where the target element occurs
        int count = 0, lindex = 0;
        
        for(int i=0; i<n; i++){
		//whenever target == nums[i] increase the count by 1 and update the lindex
            if(nums[i] == target){
                count++;
                lindex = i;
            }
        }
        
		//if count == 0 this implies target element is not in the array
        if(!count)
            return {-1,-1};
        
		//else simply return the last index where element occured - no. of target elements present + 1
		//and the last index of the target element lindex
        return {lindex - count + 1, lindex};
        
    }
};