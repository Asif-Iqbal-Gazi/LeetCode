class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num, carry = 0, 1

        for i in range(len(digits) - 1, -1, -1):
            num = digits[i] + carry
            carry = num // 10
            digits[i] = num % 10

        if carry == 1:
            digits.insert(0, 1)

        return digits
