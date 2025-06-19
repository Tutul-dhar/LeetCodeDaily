func partitionArray(nums []int, k int) int {
    sort.Ints(nums)
    ans := 1

    mn := nums[0]
    mx := nums[0]
    for i := 0; i < len(nums); i++ {
        if mx < nums[i] {
            mx = nums[i]
        }
        if mn > nums[i] {
            mn = nums[i]
        }
        if mx-mn > k {
            ans++
            mn = nums[i]
            mx = nums[i]
        }
    }

    return ans
}
