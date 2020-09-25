class CustomStack {
public:
    CustomStack(int maxSize) {
        this->ms = maxSize;
    }
    
    void push(int x) {
        if(this->x1.size() == this->ms) return;
        else this->x1.push_back(x);
    }
    
    int pop() {
        if(this->x1.size() == 0) return -1;
        int back = this->x1.back();
        this->x1.pop_back();
        return back;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k& i<x1.size(); ++i)
        {
            this->x1[i] += val;
        }
    }
private:
    vector<int> x1;
    int ms=0;
};
