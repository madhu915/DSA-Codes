class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        emap=zip(speed,efficiency)
        esort=sorted(emap,key=lambda x:x[1],reverse=True)
        mheap=[]
        sps=0
        res=0
        for s,e in esort:
            sps+=s
            heappush(mheap,s)
            if len(mheap)>k:
                sps-=heappop(mheap)
            res=max(res,sps*e)
        # return int(res%(10e9+7))
        return res%1000000007
        