class UndergroundSystem(object):

    def __init__(self):
        self.current_riders = {}
        self.station_record = {}

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.current_riders[id] = (stationName, t)
        

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        startStat, startTime = self.current_riders.pop(id)

        inandoutpair = (startStat, stationName)
        
        if inandoutpair in self.station_record:
            prevRecord = self.station_record[inandoutpair]
        else:
            prevRecord = (0, 0)
            
        self.station_record.update({inandoutpair : (prevRecord[0] + 1, prevRecord[1] + t - startTime)})        

    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        stat_rec = self.station_record[(startStation, endStation)]
        return float(stat_rec[1])/stat_rec[0]
        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)