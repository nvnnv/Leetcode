    def findKthPositive(self, arr: List[int], k: int) -> int:
        origin = {key:1 for key in range(1, len(arr)+k+1)}
        for i in arr:
            origin[i] = -1

        kth = 0
        k_co = 0;
        for i in range(1, len(arr) + k+1):
            if origin[i] == 1:
                kth += 1
                if kth == k:
                    k_co = i
                    break
        return k_co
        
