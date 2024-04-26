#include <bits/stdc++.h>
using namespace std;

// This algorithm will find the kth largest element of an unsorted vector in O(n) time

// Finding the pivot position
int findPivot(vector<int> &nums, int l, int h) {
    int pivot = nums[h];
    
    int idx = l;

    for (int i=l; i<h; ++i) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[idx]);
            idx++;
        }
    }
    swap(nums[idx], nums[h]);

    return idx;
}

// Quick Select Algorithm
int quickSelect(vector<int> &nums, int l, int h, int k) {
    int pivot = findPivot(nums, l, h);
    
    // Return current pivot position if 
    if (pivot == nums.size() - k) return nums[pivot];

    else if (pivot < nums.size() - k) {
        return quickSelect(nums, pivot + 1, h, k);
    }
    
    else {
        return quickSelect(nums, l, pivot - 1, k);
    }

    return -1;
}

int main() {

    vector<int> nums = {3,2,1,5,6,4};
    cout << quickSelect(nums, 0, nums.size() - 1, 2);

    return 0;
}