class MedianFinder {
public:

    int n;
    double median;
    priority_queue<int> maxH;
	priority_queue<int, vector<int>, greater<int>> minH;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(!maxH.empty() && maxH.top() > num){
            maxH.push(num);

            if(maxH.size() > minH.size() + 1){
                minH.push(maxH.top());
                maxH.pop();
            }
        }
        else{
            minH.push(num);
            if(minH.size() > maxH.size() + 1){
                maxH.push(minH.top());
                minH.pop();
            }
        }
        n++;    
    }
    
    double findMedian() {
        if(n & 1){
            median = maxH.size() > minH.size() ? maxH.top() : minH.top();
        }
        else{
            median = minH.top() + maxH.top();
            median /= 2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
