#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            // nums1'i her zaman daha kısa tut
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Sol ve sağ bölmelerin elemanlarını belirle
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Doğru bölmeyi bulduk mu?
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Toplam eleman sayısı tek mi çift mi kontrol et
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) {
                // Bölmeyi sola kaydır
                high = partitionX - 1;
            } 
            else {
                // Bölmeyi sağa kaydır
                low = partitionX + 1;
            }
        }

        throw invalid_argument("Input arrays are not valid.");
    }
};
