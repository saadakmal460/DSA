#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include<fstream>
#include <random>
#include<ctime>

using namespace std;

class Compare {
public:
    bool operator() (int& a,int& b) 
    {
        return a > b;
    }
};

// Task 2
template<class T>
void HeapSort(vector<T>& V)
{
    priority_queue<T, vector<T>, Compare> PQ;

    for (int i = 0; i < V.size(); i++)
    {
        PQ.push(V[i]);
    }

    V.clear();

    while (!PQ.empty())
    {
        V.push_back(PQ.top());
        PQ.pop();
    }
}

// Task 3
void Randomized_Init(vector<int>& V)
{
    for (int i = 0; i < V.size(); i++)
    {
        V[i] = rand() % 100;
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

//Task 6
//Geeks For Geeks

int partition(vector<int>& arr, int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}


void quickSort(vector<int>& arr, int l, int h)
{
    if (l < h) {
        
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}





void createRandomFile(string fileName, int size)
{
    ofstream file(fileName);
    for (int i = 0; i < size * 1024; i++)
    {
        file << rand() % 10 << " ";
    }

}

void LoadData(string fileName , vector<int>&v)
{
    ifstream file(fileName);
    int value;

    while (file >> value)
    {
        v.push_back(value);
    }

    file.close();
}




int main() {
    vector<int> v;

   
    //createRandomFile("dsa.txt", 500);

    LoadData("dsa.txt", v);

   

    cout << "Time Before sorting: " << time(0) << endl;
    
    quickSort(v , 0 , v.size()-1);


    cout << "Time After sorting: " << time(0) << endl;


    
}
