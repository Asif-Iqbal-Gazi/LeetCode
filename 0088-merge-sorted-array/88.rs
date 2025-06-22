impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let (mut i, mut j, mut k) = (m - 1, n - 1, m + n - 1);

        while i >= 0 && j >= 0 {
            let (ii, jj, kk) = (i as usize, j as usize, k as usize);
            if nums1[ii] > nums2[jj] {
                nums1[kk] = nums1[ii];
                i -= 1;
            } else {
                nums1[kk] = nums2[jj];
                j -= 1;
            }
            k -= 1;
        }

        while j >= 0 {
            let (jj, kk) = (j as usize, k as usize);
            nums1[kk] = nums2[jj];
            j -= 1;
            k -= 1;
        }
    }
}
