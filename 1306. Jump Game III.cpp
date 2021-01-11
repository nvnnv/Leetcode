    def canReach(self, arr: List[int], start: int) -> bool:
        v = [0 for i in arr]
        def jump (arr, start):
            if start < 0 or start >= len(arr) or v[start] == 1:
                return False
            if arr[start] == 0:
                return True
            v[start] = 1
            return jump(arr, start + arr[start]) or jump(arr, start - arr[start])
    
        return jump(arr, start)
