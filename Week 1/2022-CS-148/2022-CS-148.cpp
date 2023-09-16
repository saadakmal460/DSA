#include <iostream>
#include <vector>
using namespace std;

//Reg no: 2022-CS-148
int main()
{
    
}

//Problem number 1
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

//Problem number 2
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

//Problem number 3
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m * n) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / n, col = mid % n;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

//Problem number 4
int removeDuplicates(vector<int>& nums) {
    vector<int> num2;
    int k = 1;

    for (int i = 1; i < nums.size(); i++)
    {

        if (nums[i] != nums[k - 1])
        {
            nums[k] = nums[i];
            k++;

        }

    }
    return k;
}


//Problem number 5
int maxSubArray(vector<int>& nums) {
    int maxSum = -1000000;
    int current = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        current = current + nums[i];
        if (current > maxSum)
        {
            maxSum = current;
        }

        if (current < 0)
        {
            current = 0;
        }
    }

    return maxSum;

}

//Problem number 6
int firstBadVersion(int n) {

    int start = 0;
    int end = n;
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isBadVersion(mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return result;
}

//Problem number 7
int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == count)
        {
            count++;
        }
    }

    return count;
}
