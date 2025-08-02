class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> merge; //declare merged vector with allocated size
        merge.insert(merge.end(), nums1.begin(), nums1.end());
        merge.insert(merge.end(), nums2.begin(), nums2.end());

        sort(merge.begin(), merge.end());

        int n = merge.size();

        if(n % 2 == 1)//if odd
        {
            return merge[n/2];
        }
        else//if even
        {
            return (merge[n / 2 - 1] + merge[n / 2]) / 2.0;
        }
    }
};