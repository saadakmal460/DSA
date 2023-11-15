#include <iostream>



int main()
{
    std::cout << "Hello World!\n";
}

//Problem 1
class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                myStack.push(s[i]);
            }
            else {
                if (!myStack.empty() && ((s[i] == ')' && myStack.top() == '(') || (s[i] == ']' && myStack.top() == '[') || (s[i] == '}' && myStack.top() == '{'))) {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
        }

        return myStack.empty();
    }

};

//Problem 2
class MinStack {
public:
    stack<int>s, minStack;
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

//Problem 3



//Problem 4
class Solution {
public:
    string decodeString(string s) {
        stack<char> ch;
        string decoded = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c != ']') {
                ch.push(c);
            }
            else {
                string subString = "";
                while (!ch.empty() && ch.top() != '[') {
                    subString = ch.top() + subString;
                    ch.pop();
                }
                ch.pop();

                string num = "";
                while (!ch.empty() && isdigit(ch.top())) {
                    num = ch.top() + num;
                    ch.pop();
                }

                int repeatCount = stoi(num);

                for (int j = 0; j < repeatCount; j++) {

                    for (int k = 0; k < subString.length(); k++) {
                        ch.push(subString[k]);
                    }
                }
            }
        }

        while (!ch.empty()) {
            decoded = ch.top() + decoded;
            ch.pop();
        }

        return decoded;
    }
};

//Problem 5
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int width = right - left;
            int area2 = min(height[left], height[right]) * width;

            if (area2 > area)
            {
                area = area2;
            }

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return area;
    }
};


//Problem 6
class MyStack {
public:
    queue<int> q;
    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        for (int i = 0; i < q.size() - 1; i++)
        {
            push(q.front());
            q.pop();
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

//Problem 7
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int studentsCount = students.size();
        int circle = 0, square = 0;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
            {
                circle++;
            }
            else
            {
                square++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0)
            {
                if (circle > 0)
                {
                    circle--;
                    studentsCount--;
                }
                else
                {
                    return studentsCount;
                }
            }
            else
            {
                if (square > 0)
                {
                    square--;
                    studentsCount--;
                }
                else
                {
                    return studentsCount;
                }
            }

        }
        return studentsCount;
    }
};


//Problem 8
class FrontMiddleBackQueue {
public:
    deque<int> q1, q2;
    int n1 = 0, n2 = 0;
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        q1.push_front(val);
        if (n1 == n2)
        {
            n1++;
        }
        else
        {
            q2.push_front(q1.back());
            q1.pop_back();
            n2++;
        }
    }

    void pushMiddle(int val) {
        if (n1 == n2)
        {
            q1.push_back(val);
            n1++;
        }
        else
        {
            q2.push_front(q1.back());
            q1.pop_back();
            q1.push_back(val);
            n2++;
        }
    }

    void pushBack(int val) {
        q2.push_back(val);
        if (n2 < n1)
        {
            n2++;
        }
        else
        {
            q1.push_back(q2.front());
            q2.pop_front();
            n1++;
        }
    }

    int popFront() {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        int ans = q1.front();
        q1.pop_front();
        n1--;
        if (n1 < n2)
        {
            q1.push_back(q2.front());
            q2.pop_front();
            n2--;
            n1++;
        }
        return ans;
    }

    int popMiddle() {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        int ans = q1.back();
        q1.pop_back();
        n1--;
        if (n1 < n2)
        {
            q1.push_back(q2.front());
            q2.pop_front();
            n2--;
            n1++;
        }
        return ans;
    }


    int popBack() {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        if (n2 == 0)
        {
            int ans = q1.back();
            q1.pop_back();
            n1--;
            return ans;
        }
        int ans = q2.back();
        q2.pop_back();
        n2--;
        if (n2 + 1 < n1)
        {
            q2.push_front(q1.back());
            q1.pop_back();
            n1--;
            n2++;
        }
        return ans;

    }
};




//Problem 9
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0];
        int currentMax = 0, currentMin = 0, total = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (currentMax + nums[i] > nums[i])
            {
                currentMax = currentMax + nums[i];
            }
            else
            {
                currentMax = nums[i];
            }

            if (currentMin + nums[i] < nums[i])
            {
                currentMin = currentMin + nums[i];
            }
            else
            {
                currentMin = nums[i];
            }

            total += nums[i];
            if (globalMax < currentMax)
            {
                globalMax = currentMax;
            }
            if (globalMin > currentMin)
            {
                globalMin = currentMin;
            }


        }

        if (globalMax <= 0)
        {
            return globalMax;
        }

        if (total - globalMin > globalMax) {
            return total - globalMin;
        }
        else {
            return globalMax;
        }

    }
};



//Problem 10
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> mag;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (mag.empty() || asteroids[i] > 0)
            {
                mag.push_back(asteroids[i]);
            }
            else
            {
                bool crash = false;
                while (!mag.empty() && mag.back() > 0)
                {
                    int top = mag.back();
                    mag.pop_back();

                    if (top + asteroids[i] == 0)
                    {
                        crash = true;
                        break;
                    }
                    else if (top + asteroids[i] > 0)
                    {
                        crash = true;
                        mag.push_back(top);
                        break;
                    }

                }
                if (!crash)
                {
                    mag.push_back(asteroids[i]);
                }
            }

        }
        return mag;


    }


};
