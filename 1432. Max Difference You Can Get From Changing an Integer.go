func maxDiff(num int) int {
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
    p = 0
    if str[0] != '1' {
        p = str[0]
        for i := 0; i < len(str); i++ {
            if str[i] == p {
                mn[i] = '1';
            }
        }
    } else {
        for i := 1; i < len(str); i++ {
            if str[i] != str[0] && p == 0 && str[i] != '0' {
                p = str[i]
            }
            if str[i] == p {
                mn[i] = '0'
            }
        }
    }
    mxInt,_ := strconv.Atoi(string(mx))
    mnInt,_ := strconv.Atoi(string(mn))
    //fmt.Println(mnInt, mxInt)
    return (mxInt - mnInt)
}
