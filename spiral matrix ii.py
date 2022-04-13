class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        direction = 0
        segment_length = n
        curr_segment = 0
        times = True
        ret = [[0]*n for _ in range(n)]
        curr_m,curr_n=0, 0
        
        for i in range(1, n**2 + 1):
            ret[curr_m][curr_n] = i
            
            curr_segment += 1
            
            if curr_segment == segment_length:
                curr_segment = 0
                direction = (direction+1)%4
                
                if times:
                    times = not times
                    segment_length -= 1
                else:
                    times = not times
                    
            if direction==0:
                curr_n += 1
            elif direction==1:
                curr_m += 1
            elif direction==2:
                curr_n -= 1
            else:
                curr_m -= 1
                
            
        return ret
