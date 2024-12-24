def solve():
    cur = 0
    d = {}

    def a(x):
        nonlocal cur
        if x in d:
            return str(d[x])
        cur += 1
        d[x] = cur
        return x

    s = input()
    while len(s) > 0:
        ans = []
        i = j = 0
        while i < len(s):
            while i < len(s) and not (s[i].isalpha()):
                ans.append(s[i])
                i += 1

            j = i + 1
            while j <= len(s):
                if j == len(s) or not (s[j].isalpha()):
                    ans.append(a(s[i:j]))
                    i = j
                    break
                j += 1

            if i < len(s):
                ans.append(s[i])
            i += 1

        print("".join(ans))
        s = input()
    print("")


try:
    for _ in range(int(input())):
        solve()
except EOFError:
    pass
