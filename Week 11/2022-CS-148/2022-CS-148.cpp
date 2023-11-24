#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

template<class T>
class Compare {
public:
    bool operator() (const int& a, const int& b) const {
        return a >= b;
    }
};

// Task 2
template<class T>
void HeapSort(vector<T>& v) {
    priority_queue<T, vector<T>, Compare<T>> pq;

    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i]);
    }
    v.clear();

    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
}

// Task 3
void RandomizedInt(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }
}

void Print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
    cout << endl << endl << endl;
}


//Task 4
template<class T>
bool SwapingAllTheWay(vector<T>&v)
{
    bool flag = false;
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] > v[i + 1])
        {
            swap(v[i], v[i + 1]);
            flag = true;
        }
    }
    return flag;
}

template<class T>
void BubbleSort(vector<T>& v)
{
    while (SwapingAllTheWay(v))
    {

    }
}




int main() {
    vector<int> v(25);
    RandomizedInt(v);

    cout << "Before sorting: " << endl;
    Print(v);

    HeapSort(v);

    cout << "After sorting: " << endl;
    Print(v);

    return 0;
}
