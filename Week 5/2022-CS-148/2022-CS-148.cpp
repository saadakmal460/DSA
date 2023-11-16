#include <iostream>
#include <cmath>
#include<string>
#include <vector>
#include <stack>
using namespace std;


//Question 1

int SumOfN(int n) //Part 1
{
    if (n == 0)
    {
        return 0;
    }
    return n+ SumOfN(n - 1);
}

int SumOfOdd(int n) //Part 2
{
    if (n == 1)
    {
        return 1;
    }
    return n + SumOfOdd(n - 2);
}

int PowerSum2(int n) //Part 3
{
    if (n == 0)
    {
        return 1;
    }
    return pow(2,n) + PowerSum2(n - 1);
}

int PowerSum3(int n) //Part 4
{
    if (n == 0)
    {
        return 1;
    }
    return pow(3, n) + PowerSum3(n - 1);

}

int geometricSumOf3(int n) //Part 5
{
    if (n == 1)
    {
        return 1;
    }
    return n + geometricSumOf3(n/3);

}

int geometricSumOf2(int n) //Part 6
{
    if (n == 1)
    {
        return 1;
    }
    return n + geometricSumOf2(n / 2);

}

//Question 2

int DecToBin(int n) //Part 1
{
    if (n == 0)
    {
        return 0;
    }
    return (DecToBin(n / 2) * 10) + (n % 2);
}

string IntToString(int n) //Part 2
{
    if (n == 0)
    {
        return "0";
    }

    return IntToString(n / 10) + to_string(n % 10);

}

int GCD(int a, int b) //Part 3
{
    if (a % b == 0)
    {
        return b;
    }

    return GCD(b, a % b);
}


//Question 3

int searchFirst(int arr[], int n , int count , int length) //Part 1
{
    if (arr[count] == n)
    {
        return count;
    }
    if (count == length)
    {
        return -1;
    }
    
    return searchFirst(arr, n, ++count ,length);
}

int SearchLast(int arr[], int n, int count, int length) //Part 2
{
    if (arr[count] == n)
    {
        return count;
    }
    if (count == 0)
    {
        return -1;
    }

    return searchFirst(arr, n, --count, length);
}

int BinarySearch(int arr[] , int n , int start , int end) //Part 3
{
    int mid = (start + end) / 2;
    if (arr[mid] == n)
    {
        return mid;
    }
    else if (arr[mid] < n)
    {
        return BinarySearch(arr, n, start = mid + 1 ,end);
    }

    return BinarySearch(arr, n, start , end = mid-1);

}

//Question 4
int ComputePower(int x, int y, int m)
{
    int power;
    if (y == 0)
    {
        return 1;
    }
    power = x * ComputePower(x, y - 1, m);
    return x % m;

}


//Question 5
int Add(int a, int b) 
{
    return a + b;
}

int Mul(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    return Add(a, Mul(a, b - 1));
}


int MulMem(vector<int>&num , int a, int b)
{
    if (b == 0) {
        return 0;
    }

    if (num[a] != -1) {
        return num[a];
    }

    int result = Add(a, MulMem(num , a, b - 1));;

    num[a] = result;

    return result;
}

//Question 6
int ComputeAdivB(int a, int b) //Part 1
{
    if (a - b == 0)
    {
        return 1;
    }

    return 1 + ComputeAdivB(a - b, b);
}

int ComputeAdivBMem(vector<int>&num , int a, int b) //Part 2
{
    if (a - b == 0) {
        return 1;
    }

    if (num[a] != -1) {
        return num[a];
    }

    int result = 1 + ComputeAdivBMem(num , a - b, b);

    num[a] = result; 

    return result;
}


//Question 7
int FibWithMem(vector<int>& num , int n) //Part 1,2
{
    if (n <= 1)
    {
        return n;
    }
    if (num[n] != -1)
    {
        return num[n];
    }
    return num[n] = FibWithMem(num , n - 1) + FibWithMem(num , n - 2);

}
int FibWithTabulation(int n) //Part 3
{
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];

}

//Question 8
int TriSumRecursive(int n) //Part 1
{
    if (n <= 3)
    {
        return n;
    }

    return TriSumRecursive(n - 1) + TriSumRecursive(n - 2) + TriSumRecursive(n - 3);
}

int TriSumMem(vector<int>& num, int n)//Part 2
{
    if (n <= 3)
    {
        return n;
    }
    if (num[n] != -1)
    {
        return num[n];
    }

    return num[n] = TriSumMem(num, n - 1) + TriSumMem(num, n - 2) + TriSumMem(num, n - 3);
}

int TriSumTab(int n) //Part 3
{
    vector<int> num(n + 1);
    num[0] = 0;
    num[1] = 1;
    num[2] = 2;

    
    for (int i = 3; i <= n; i++)
    {
        num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    }
    return num[n];
}


//Challenge 1

void ChallengeOne(vector<int> arr , int start , vector<string>&subArray)
{
    string str = "";
    
    if (start == arr.size())
    {
        subArray.push_back("[ ]");
        return;
    }
    for (int i = start; i < arr.size(); i++)
    {
        str += " " + to_string(arr[i]) + " ";
        subArray.push_back("[" + str + "]");
    }

    ChallengeOne(arr, start + 1 , subArray); 

}

//Challenge 2

void ArrangeStack(stack<int>& s, int num)
{
    if (s.empty() || s.top() <= num)
    {
        s.push(num);
    }
    else
    {
        int temp = s.top();
        s.pop();
        ArrangeStack(s, num);
        s.push(temp);
    }
}

void SortStack(stack<int>& s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        SortStack(s);
        ArrangeStack(s, temp);
    }
}


int main()
{
    cout << FibWithTabulation(2);
      
}

