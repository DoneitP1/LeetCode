impl Solution {
    pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut pref_sum = vec![0; nums.len() + 1];

        for i in 0..k {
            pref_sum[k] += nums[i];
        }

        for i in (k + 1)..=nums.len() {
            pref_sum[i] = pref_sum[i - 1] + nums[i - 1] - nums[i - 1 - k];
        }

        let mut pref_sum_pref_max = vec![0; nums.len() + 1];
        pref_sum_pref_max[2 * k] = k;

        for i in (2 * k + 1)..=nums.len() {
            pref_sum_pref_max[i] = if pref_sum[i - k] > pref_sum[pref_sum_pref_max[i - 1]] {
                i - k
            } else {
                pref_sum_pref_max[i - 1]
            };
        }

        let mut pref_sum_pref_max_pref_max = vec![0; nums.len() + 1];
        pref_sum_pref_max_pref_max[3 * k] = 2 * k;

        for i in (3 * k + 1)..=nums.len() {
            pref_sum_pref_max_pref_max[i] = if
                pref_sum[i - k] + pref_sum[pref_sum_pref_max[i - k]] >
                pref_sum[pref_sum_pref_max_pref_max[i - 1]] + pref_sum[pref_sum_pref_max[pref_sum_pref_max_pref_max[i - 1]]]
            {
                i - k
            } else {
                pref_sum_pref_max_pref_max[i - 1]
            }
        }
        let mut max = 0;
        let mut ans = (0, 0, 0);

        for i in (3 * k)..=nums.len() {
            let a = i;
            let b = pref_sum_pref_max_pref_max[i];
            let c = pref_sum_pref_max[pref_sum_pref_max_pref_max[i]];
            let s = pref_sum[a] + pref_sum[b] + pref_sum[c];
            let new_ans = (c - k, b - k, a - k);

            if s > max {
                max = s;
                ans = new_ans;
            }

            if s == max {
                if ans > new_ans {
                    ans = new_ans;
                }
            }
        }

        vec![ans.0 as i32, ans.1 as i32, ans.2 as i32]
    }
}