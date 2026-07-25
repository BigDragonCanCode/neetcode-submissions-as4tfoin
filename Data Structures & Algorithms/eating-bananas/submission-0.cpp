class Solution {
public:
    //with eating rate k can we finish within h hours
    bool isValid(vector<int>& piles, int k, int& h) {
        int time = 0;

        for (int& p: piles) {
            time += ceil((double)p/k);
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        //the upper bound is bounded by the
        //maximum number in the pile
        //eating faster than the largest pile give no benefit
        int r = *max_element(piles.begin(), piles.end());

        int res = INT_MAX;
        while (l <= r) {
            int mid = l + (r-l)/2;
            
            //if valid we update the choice of k
            if (isValid(piles, mid, h)) {
                res = min (res, mid);
                // try to search the left side to find even smaller k
                r = mid - 1;
            } else {
                //not valid means too slow so we need to increase k
                l = mid + 1;
            }
        }

        return res;
    }
};
