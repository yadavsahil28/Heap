class Solution
{
    public:
    
    class Info{
        public:
        int data;
        int row;
        int col;
        
        Info(){
            
        }
        
        Info(int d, int r, int c){
            this->data = d;
            this->row = r;
            this->col = c;
        }
    };
    
    class Cmp{
        public:
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
        }
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        int n = arr[0].size();
        priority_queue<Info*, vector<Info*>, Cmp> q;
        
        for(int i=0; i<K; i++){
            int element = arr[i][0];
            Info* temp = new Info(element,i,0);
            q.push(temp);
        }
        
        while(!q.empty()){
            Info* temp = q.top();
            q.pop();
            ans.push_back(temp->data);
            
            if(temp->col + 1 < n){
                int element = arr[temp->row][temp->col+1];
                Info* toPush = new Info(element, temp->row, temp->col+1);
                q.push(toPush);
            }
        }
        return ans;
    }
}
