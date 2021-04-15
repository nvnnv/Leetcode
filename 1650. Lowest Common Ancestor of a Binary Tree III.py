class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        if q is None or p is None:
            return None
        trace = {}
        p1 = p
        while p1 is not None:
            trace[p1.val] = 1
            p1 = p1.parent
        q1 = q
        while q1 is not None:
            if trace.get(q1.val) is not None:
                return q1
            q1 = q1.parent
        return None
