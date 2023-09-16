#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class AutoGrowingArray
{
private:
    int size;
    int capacity;
    T* DA;
public:
    AutoGrowingArray()
    {
        size = 0;
        capacity = 2;
        DA = new T[capacity];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << DA[i] << endl;
        }
    }
    void pushBack(T value)
    {
        if (size == capacity)
        {
            capacity = capacity*1.5;
            T* HA = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                HA[i] = DA[i];
            }

            delete[]DA;
            DA = HA;
        }

        DA[size] = value;
        size++;

    }

    T& operator [](int index)
    {
        return DA[index];
    }

    friend ostream& operator<<(ostream& out, const AutoGrowingArray& Other)
    {

        for (int i = 0; i < Other.size; ++i) {
            out << Other.DA[i] << endl;
        }
        return out;
    }

    void createRandomFile(string fileName , int size)
    {
        ofstream file(fileName);
        for (int i = 0; i < size*1024*1024; i++)
        {
            file << rand() % 10 << " ";
        }

    }

    void LoadData(string fileName)
    {
        ifstream file(fileName);
        int value;

        while (file >> value)
        {
            pushBack(value);
        }

        file.close();
    }
};



int main()
{
    /*AutoGrowingArray<int> a;
    
    a.createRandomFile("dsa.txt" , 1);
    cout << "Before Loading " << time(0) <<endl;
    a.LoadData("dsa.txt");
    cout << "After Loading " << time(0);*/

    int arr[3][3] = { {1,2,3},
                       {1,2,3},{1,2,3} };




}


