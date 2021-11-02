# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        q = []
        h = head
        while h is not None:
            q.append(h)
            h=h.next
        qc = []
        for i in range(1, len(q)-1):
            if (q[i-1].val < q[i].val > q[i+1].val) or (q[i-1].val >q[i].val <q[i+1].val):
                qc.append(i)
        f = [1e9,-1]
        if len(qc) < 2:
            return [-1,-1]
        f[1] = (qc[-1]+1)-(qc[0]+1)
        for i in range(1,len(qc)):
            f[0] = min(f[0], qc[i]-qc[i-1])
        return f
