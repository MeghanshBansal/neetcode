class MedianFinder {
public:
    // first half will always have equal or second_half.size() + 1 elements
    priority_queue<int> first_half;
    priority_queue<int, vector<int>, greater<int>> second_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {  
        // check in which half value needs to be pushed
        if (first_half.empty() || num <= first_half.top())
            first_half.push(num);
        else
            second_half.push(num);

        // balance the heaps to maintain the size conditions that first_half has equal or more elements
        // push in second half if first half size is too much
        if (first_half.size() > second_half.size() + 1)
        {
            second_half.push(first_half.top());
            first_half.pop();
        }

        // push in first half if second half size is too much
        if (second_half.size() > first_half.size())
        {
            first_half.push(second_half.top());
            second_half.pop();
        }
    }
    
    double findMedian() {
        if (first_half.size() > second_half.size()) return static_cast<double>(first_half.top());
        else  return (static_cast<double>(first_half.top()) + static_cast<double>(second_half.top())) / 2.0;
    }
};
