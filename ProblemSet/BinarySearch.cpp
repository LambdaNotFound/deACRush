#include "BinarySearch.h"

// 4. Median of Two Sorted Arrays
double BinarySearch::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size(), half = (m + n + 1) / 2;
    int left = 0, right = min(half, m);
    while (left < right) {
        int mid1 = left + (right - left) / 2;
        int mid2 = half - mid1;

        if (nums2[mid2 - 1] > nums1[mid1])
            left = mid1 + 1;
        else
            right = mid1;
    }

    int m1 = left, m2 = half - m1;
    int leftMedian = max(m1 > 0 ? nums1[m1 - 1] : INT_MIN, m2 > 0 ? nums2[m2 - 1] : INT_MIN);

    if ((m + n) % 2 == 1)
        return (double)leftMedian;

    int rightMedian = min(m1 < m ? nums1[m1] : INT_MAX, m2 < n ? nums2[m2] : INT_MAX);

    return (leftMedian + rightMedian) / 2.0;
}

double BinarySearch::findMedianSortedArraysGeneral(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    return (findKthSmallestElement(nums1, 0, nums2, 0, (m + n + 1) / 2) + findKthSmallestElement(nums1, 0, nums2, 0, (m + n + 2) / 2)) / 2.0;
}
double BinarySearch::findKthSmallestElement(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (i >= nums1.size())
        return nums2[j + k - 1];
    if (j >= nums2.size())
        return nums1[i + k - 1];
    if (k == 1)
        return min(nums1[i], nums2[j]);

    int mid1 = i + k / 2 - 1 < nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
    int mid2 = j + k / 2 - 1 < nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;
    if (mid1 > mid2)
        return findKthSmallestElement(nums1, i, nums2, j + k / 2, k - k / 2);
    else
        return findKthSmallestElement(nums1, i + k / 2, nums2, j, k - k / 2);
}

// 300. Longest Increasing Subsequence
int BinarySearch::lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;

    int L = 1;
    vector<int> M(nums.size() + 1, 0); // M[i]: min of last value of LIS ending at i
    vector<int> P(nums.size(), 0); // P[i]: previous last value's index in the LIS
    for (int i = 1; i < nums.size(); ++i) {
        int upperBound = findUpperBound(nums, M, L, nums[i]);
        if (nums[i] == nums[M[upperBound - 1]])
            continue; // skip duplicates

        M[upperBound] = i; // append num[i] (+1) to LIS of length == upperBound - 1
        P[i] = M[upperBound - 1];
        L = max(upperBound, L);
    }

    vector<int> LIS(L, 0);
    for (int j = L - 1, k = M[L]; j >= 0; --j) {
        LIS[j] = nums[k];
        k = P[k];
    }

    return LIS.size();
}
int BinarySearch::findUpperBound(const vector<int>& nums, const vector<int>& M, int len, int num) {
    int low = 1, high = len;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[M[mid]] <= num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int BinarySearch::lengthOfLISDP(vector<int>& nums) {
    int n = nums.size(), res = 1;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }

    return res;
}
