
func minMaxDifference(num int) int {
    str := strconv.Itoa(num)
    mn, mx := []byte(str),[]byte(str)
    var p byte = 0
    for i := 0; i < len(str); i++ {
        ch := str[i]
        if ch != '9' && p == 0 {
            p = ch
        }
        if ch == p {
            mx[i] = '9'
        }
    }
    p = mn[0]
    for i := 0; i < len(str); i++ {
        ch := str[i]
        if ch == p {
            mn[i] = '0'
        }
    }

    mxInt,_ := strconv.Atoi(string(mx))
    mnInt,_ := strconv.Atoi(string(mn))

    return (mxInt - mnInt)
}
