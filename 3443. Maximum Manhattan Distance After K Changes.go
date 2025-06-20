func Max(a int, b int) int {
    if a < b {
        return b
    }
    return a
}

func Min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}


func maxDistance(s string, k int) int {
    x1,x2,y1,y2 := 0,0,0,0
    ans := 0
    for i:= 0; i < len(s); i++ {
        if s[i] == 'N' {
            x1++
        } else if s[i] == 'S' {
            x2++;
        } else if s[i] == 'E' {
            y1++
        } else {
            y2++
        }

        p := k
        xx1, xx2, yy1,yy2 := x1,x2,y1,y2

        if xx1 > xx2 {
            q := xx1
            xx1 = xx2
            xx2 = q
        }

        if yy1 > yy2 {
            q := yy1
            yy1 = yy2
            yy2 = q
        }
        res := xx2 + yy2
        c := min(p,xx1)
        res += c
        p -= c
        xx1 -= c

        c = min(p,yy1)
        res += c
        yy1 -= c
        res -= xx1
        res -= yy1
        ans = Max(res,ans)
    }

    return ans
}
