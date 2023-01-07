/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution
{
private:
    string one[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numToWords(int n)
    {
        if (n >= 1000000000)
            return numToWords(n / 1000000000) + " Billion" + numToWords(n % 1000000000);
        if (n >= 1000000)
            return numToWords(n / 1000000) + " Million" + numToWords(n % 1000000);
        if (n >= 1000)
            return numToWords(n / 1000) + " Thousand" + numToWords(n % 1000);
        if (n >= 100)
            return numToWords(n / 100) + " Hundred" + numToWords(n % 100);
        if (n >= 20)
            return " " + tens[n / 10] + numToWords(n % 10);
        if (n >= 1)
            return " " + one[n];
        return "";
    }

public:
    string numberToWords(int num)
    {
        /* Approach:
            1. Recursion
        */

        if (num == 0)
            return "Zero";
        return numToWords(num).substr(1);
    }
};
// @lc code=end
