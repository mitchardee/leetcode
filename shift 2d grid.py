class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        return [[grid[(i*n + j - k) % (m*n) / n][(i*n + j - k) % (m*n) % n] for j in range(n)] for i in range(m)]