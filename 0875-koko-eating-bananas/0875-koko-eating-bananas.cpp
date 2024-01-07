class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int left = 1;
        int right = piles[n-1];

        while (left < right) {
            int mid = (left + right)/2;
            int eatHour = 0;

            for (int pile: piles) {
                eatHour += pile / mid;
                if (pile % mid) eatHour++;
            }
            if (eatHour <= h) {
                right = mid;
            }
            else if (eatHour > h) {
                left = mid+1;
            }
        }
        return left;
    }
};