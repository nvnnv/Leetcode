class Solution:
    def countStudents(self, st: List[int], sa: List[int]) -> int:
        i = 0
        s = []
        f = 0
        while len(st) > 0:
            if st[0] == sa[0]:
                sa.pop(0)
                st.pop(0)
                f = 1
            else:
                s.append(st.pop(0))
            if len(st) == 0:
                #print(s, f)
                if f == 1:
                    st = s + st
                    f = 0
                    s = []
                else:
                    return len(s)
        return len(st)
