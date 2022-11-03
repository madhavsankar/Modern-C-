#include <bits/stdc++.h>

using namespace std;

class BoundedBlockingQueue {
    int capacity;
    queue<int> q;
    
    mutex mu;
    condition_variable cond_empty;
    condition_variable cond_full;
    
    bool isFull()
    {
        return q.size() == capacity;
    }
    
    bool isEmpty()
    {
        return q.empty();
    }
    
public:
    BoundedBlockingQueue(int capacity) {
        capacity = capacity;
    }
    
    void enqueue(int element) {
        // Lock
        unique_lock<mutex> l(mu);
        
        // Wait till not full
        cond_full.wait(l, [this](){ return !isFull(); });
        
        // Critical Section
        q.push(element);
        
        // Unlock
        l.unlock();
        
        // Notify not empty
        cond_empty.notify_one();
    }
    
    int dequeue() {
        // Lock
        unique_lock<mutex> l(mu);
        
        // Wait till not empty
        cond_empty.wait(l, [this](){ return !isEmpty(); });
        
        // Critical Section
        int ans = 0;
        ans = q.front();
        q.pop();
        
        // Unlock
        l.unlock();
        
        // Notify not full
        cond_full.notify_one();
        return ans;
    }
    
    int size() {
        unique_lock<mutex> l(mu);
        return q.size();
    }
};

int main()
{
    BoundedBlockingQueue* b1 = new BoundedBlockingQueue(20);
    vector<thread> threads;
    
    for(int i=0;i<10;i++)
    {
        threads.push_back(thread(&BoundedBlockingQueue::enqueue, b1, i));
        threads.push_back(thread(&BoundedBlockingQueue::dequeue, b1));
    }
    
    for(int i=0;i<20;i++)
        threads[i].join();
    
    delete b1;
    return 0;
}