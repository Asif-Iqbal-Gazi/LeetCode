int reverseBits(int n) {
    /* Approach:
     *  - Bit Manipulation -- T.C: O(1), S.C: O(1)
     */
    int res = 0;

    for (int i = 0; i < 32; i++) {
        int bit = (n >> i) & 1;
        res |= (bit << (31 - i));
    }

    return res;
}
