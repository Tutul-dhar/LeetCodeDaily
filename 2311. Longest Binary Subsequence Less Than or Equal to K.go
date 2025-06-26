func longestSubsequence(s string, k int) int {
    pow := make([]int,32)
    val := 1
    for i := 0; i < 32; i++ {
        pow[i] = val
        val *= 2
    }
    val = 0
    ans := 0
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '1' {
            if ans < 32 && val + pow[ans] <= k {
                val += pow[ans]
                ans++
            }
        } else {
            ans++
        }
    }

    return ans
}
