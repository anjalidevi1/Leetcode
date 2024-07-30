Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


  class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canEatAllBananas = [&](int k) {
            int totalHours = 0;
            for (int pile : piles) {
                totalHours += (pile + k - 1) / k; // This is equivalent to ceiling(pile / k)
            }
            return totalHours <= h;
        };
        
        // Binary search between 1 and the largest pile size.
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAllBananas(mid)) {
                right = mid; // Try for a smaller speed
            } else {
                left = mid + 1; // Increase speed
            }
        }
        
        return left;

    }
};



