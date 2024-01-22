class Solution {
public:
    class Info {
        public:
        int data;
        int row;
        int col;
        Info() {

        }
        Info(int d, int r, int c) {
            this->data = d;
            this->row = r;
            this->col = c;
        }
    };

    class Cmp {
        public:
        bool operator()(Info* a, Info* b) {
            return a->data > b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Info*, vector<Info*>, Cmp > minHeap; 
        
        for(int i=0; i<k; i++){
            int element = arr[i][0];
            mini = min(mini,element);
            maxi = max(maxi,element);
            Info* temp = new Info(element,i,0);
            minHeap.push(temp);
        }

        int start = mini;
        int end = maxi;

        while(minHeap.size()>0){
            Info* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;
            
            if(end - start > maxi - mini){
                start = mini;
                end = maxi;   
            }

            if(temp->col+1 < arr[temp->row].size()){
                Info* toPush = new Info(arr[temp->row][temp->col+1],temp->row,temp->col+1);
                minHeap.push(toPush);
                maxi = max(maxi,toPush->data);
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
