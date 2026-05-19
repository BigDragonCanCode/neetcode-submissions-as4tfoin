class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;
        int mask = 0xFFFFFFFF;

        for (int i=0; i<32; i++) {
            int a_bit = (a>>i) & 1;
            int b_bit = (b>>i) & 1;
            int curr_bit = a_bit ^ b_bit ^ carry; //result without carry
            carry = a_bit + b_bit + carry > 1? 1:0;
            //adding to result
            if (curr_bit) {
                res = res | (1<<i);
            }
        }
        // if (res > 0x7FFFFFFF) {
        //     res = ~(res ^ mask);
        // }
        return res;
    }
};
