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

//Task 5
template<class T>
int FindMinRange(vector<T>& v, int si, int ei)
{
    int mi = si;
    for (int i = si + 1; i <= ei; i++)
    {
        if (v[mi] > v[i])
        {
            mi = i;
        }
    }

    return mi;

}

template<class T>
void SelectionSort(vector<T>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int mi = FindMinRange(v, i, v.size() - 1);
        swap(v[i], v[mi]);
    }
}

//Task 6A
template<class T>
int Partition(vector<T>& v, int left, int right, int pi)
{
    int pivot = v[pi];
    int i = left - 1;
    int j = left;

    swap(v[pi], v[right]);
    pi = right;

    while (j < pi)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }

    swap(v[i + 1], v[pi]);
    return i + 1;
}

template<class T>
void QuickSortRec(vector<T>& v, int si, int ei)
{
    if (si < ei)
    {
        int pi = si + rand() % (ei - si + 1);
        pi = Partition(v, si, ei, pi);
        QuickSortRec(v, si, pi - 1);
        QuickSortRec(v, pi + 1, ei);
    }
}

template<class T>
void QuickSort(vector<T>& v)
{
    QuickSortRec(v, 0, v.size() - 1);
}







int main() {
    vector<int> v(25);
    RandomizedInt(v);

    cout << "Before sorting: " << endl;
    Print(v);

    QuickSort(v);

    cout << "After sorting: " << endl;
    Print(v);

    return 0;
}
