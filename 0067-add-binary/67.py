class Solution:
    def addBinary(self, a: str, b: str) -> str:
        len_a, len_b = len(a), len(b)
        max_len = max(len_a, len_b)
        res = ['0'] * (max_len + 1)  # +1 for potential carry
        i, j, k = len_a - 1, len_b - 1, max_len
        carry = 0

        while i >= 0 or j >= 0 or carry:
            total = carry
            if i >= 0:
                total += int(a[i])
                i -= 1
            if j >= 0:
                total += int(b[j])
                j -= 1
            res[k] = str(total % 2)
            carry = total // 2
            k -= 1

        return ''.join(res[k+1:])  # Skip leading zero if unused
