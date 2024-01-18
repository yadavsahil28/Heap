class Solution{
    public:
    
    void heapify(vector<int>& a, int n, int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        
        if(left<n && a[largest] < a[left]){
            largest = left;
        }
        
        if(right<n && a[largest] < a[right]){
            largest = right;
        }
        
        if(largest != index){
            swap(a[largest], a[index]);
            heapify(a,n,largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i=0; i<m; i++){
            a.push_back(b[i]);
        }
        
        for(int i=(n+m)/2-1; i>=0; i--){
            heapify(a,n+m,i);
        }
        return a;
    }
