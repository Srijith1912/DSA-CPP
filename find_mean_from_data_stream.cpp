class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}
    
    void addNum(int num) {

        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {

        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top())/2.0;
        }
        else{
            return maxHeap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */