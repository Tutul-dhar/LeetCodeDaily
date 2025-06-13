
func Abs(p int) int {
    if p < 0 {
        return p* -1
    } else {
        return p
    }
}

func minimizeMax(nums []int, p int) int {
    i , j := 0, 1000000000
    sort.Ints(nums)
    sz := len(nums)
    ans := 0
    for i <= j {
        mid := (i + j)/2
        k,cnt := 0,0
        for k+1 < sz {
            pp := Abs(nums[k] - nums[k+1])
            if pp <= mid {
                k += 2;
                cnt++;
            } else {
                k++;
            }
        }
        
        if cnt >= p {
            ans = mid
            j = mid-1
        } else {
            i = mid+1
        }
    }
    return ans
}
