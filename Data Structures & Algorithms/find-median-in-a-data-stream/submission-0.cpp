class MedianFinder {
public:

    priority_queue<int> maxH; //top is the maximum, store the smaller half
    priority_queue<int, vector<int>, greater<int>> minH; //top is minimum, store the bigger half

    MedianFinder() {}
    
    void addNum(int num) {
        if (minH.empty() || num >= minH.top())
            minH.push(num);
        else
            maxH.push(num);
        
        //re-balance
        if (maxH.size() > minH.size()+1) {
            //take away from maxH and insert to minH
            int n = maxH.top();
            maxH.pop();
            minH.push(n);
        } else if (minH.size() > maxH.size()+1) {
            int n = minH.top();
            minH.pop();
            maxH.push(n);
        }
    }
    
    double findMedian() {
        //even numbers
        double result = 0.0;
        if (maxH.size() == minH.size()) {
            result = (maxH.top()+minH.top())/2.0;
        } else if (maxH.size() > minH.size()) { //odd numbers, the bigger has the median
            result = maxH.top();
        } else {
            result = minH.top();
        }
        return result;
    }
};
