class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i=0; i<=n; i++) {
            int count = 0;
            int j=i;
            while (j>0) {
                if (j & 1)
                    count++;
                j >>= 1;
            }
            result.push_back(count);
        }
        return result;
    }
};
