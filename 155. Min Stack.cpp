// 68ms    o(1)-o(logn)   o(n) is not good
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push_back(x);
		int cur_len = data.size();
		if (min_set.size() == 0)
		{
			min_set.insert(make_pair(1, data[0]));
		}
		else
		{
			int cur_min = min_set[cur_len-1];
			if (x < cur_min) min_set.insert(make_pair(cur_len, x));
			else min_set.insert(make_pair(cur_len, cur_min));
		}
	}

	void pop() {
		data.pop_back();
		min_set.erase(min_set.find(data.size() + 1));
	}

	int top() {
		return data.back();
	}

	int min() {
		return min_set[data.size()];
	}

private:
	vector<int> data;
	map<int, int> min_set;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
