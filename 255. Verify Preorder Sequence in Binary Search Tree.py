class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        q = [preorder[0]]
        i=1
        m= -10000
        while i < len(preorder):
            if preorder[i] < m:
                return False
            if preorder[i] < q[-1]:
                q.append(preorder[i])
            else:
                a,b=q[0],q[0]
                while len(q)!=0:
                    b=a
                    a = q.pop(-1)
                    m=b
                    if a > preorder[i]:
                        q.append(a)
                        q.append(preorder[i])
                        break
                else:
                    m=a
                    q.append(preorder[i])
            
            i+=1
        return True
