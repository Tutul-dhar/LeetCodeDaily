func maxSubsequence(nums []int, k int) []int {
	ma := make(map[int]int)
	v := append([]int{}, nums...) // make a copy of nums

	sort.Sort(sort.Reverse(sort.IntSlice(v)))

	for i := 0; i < k; i++ {
		ma[v[i]]++
	}

	ans := []int{}
	for _, num := range nums {
		if ma[num] > 0 {
			ans = append(ans, num)
			ma[num]--
		}
	}

	return ans
}
