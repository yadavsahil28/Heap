class Solution {
public:

    void heapify(vector<int>& nums, int n, int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < n && nums[largest] < nums[left]){
            largest = left;
        }

        if(right < n && nums[largest] < nums[right]){
            largest = right;
        }

        if(largest != index){
            swap(nums[largest],nums[index]);
            heapify(nums,n,largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(nums,n,i);
        }

        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
        return nums;
    }
};
