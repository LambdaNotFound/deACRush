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
