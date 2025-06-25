func kthSmallestProduct(nums1 []int, nums2 []int, k int64) int64 {
    n := int64(1e5 + 2)
    pos := make([]int64,n)
    neg := make([]int64,n)
    zero := int64(0)
    for i := 0; i < len(nums2); i++ {
        if nums2[i] == 0 {
            zero++
            continue
        }
        if nums2[i] < 0 {
            neg[nums2[i]*-1]++
        } else {
            pos[nums2[i]]++
        }
    }
    for i := int64(1); i < n; i++ {
        pos[i] += pos[i-1]
        neg[i] += neg[i-1]
    }
    l := int64(-1e10)
    r := int64(1e10)
    ans := int64(0)
    for l <= r {
        mid := int64((l + r)/2)
        cnt := int64(0)
       // if mid < 10 {
            fmt.Println(mid)
       // }
        if mid < 0 {
            for i := 0; i < len(nums1); i++ {
                if nums1[i] < 0 {
                    p := mid / int64(nums1[i])
                    if p*int64(nums1[i]) > mid {
                        p++
                    }
                    if p >= n {
                        p = n-1
                    }
                    q := int64(0)
                    if p - 1 >= 0 {
                        q = pos[p - 1]
                    }
                    cnt += (pos[n-1] - q)
                } else if nums1[i] > 0 {
                    p := mid / int64(nums1[i])
                    if p*int64(nums1[i]) > mid {
                        p--
                    }
                    p *= -1
                    q := int64(0)
                    if p >= n {
                        p = n-1
                    }
                    if p - 1 >= 0 {
                        q = neg[p-1]
                    }
                    cnt += (neg[n-1] - q)
                }
            }
        } else {
            for i := 0; i < len(nums1); i++ {
                cnt += zero
                if nums1[i] == 0 {
                    cnt += pos[n-1]
                    cnt += neg[n-1]
                    continue
                }
                if nums1[i] < 0 {
                    p := mid / int64(nums1[i])
                    p *= -1
                    if p >= n {
                        p = n-1
                    }
                    cnt += neg[p]
                    cnt += pos[n-1]
                } else if nums1[i] > 0 {
                    p := mid / int64(nums1[i])
                    if p >= n {
                        p = n-1
                    }
                    cnt += pos[p]
                    cnt += neg[n-1]
                }
            }
        }

        if cnt >= k {
            ans = mid
            r = mid -1
        } else {
            l = mid+1
        }
    }

    return ans
}
