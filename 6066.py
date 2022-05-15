class CountIntervals:
    def __init__(self):
        self.intervals = []

    def binary_search(self, v):
        lo = 0
        hi = len(self.intervals)

        while lo < hi:
            mid = (lo + hi) // 2
            if self.intervals[mid][0] > v:
                hi = mid
            else:
                lo = mid if lo != mid else lo + 1

        return lo - 1

    def add(self, left: int, right: int) -> None:
        if len(self.intervals) == 0:
            self.intervals.append([left, right])
            return

        i = self.binary_search(left)
        j = self.binary_search(right)
        print(i)
        print(j)
        if i == -1:
            k = 0
            while len(self.intervals) > 0 and self.intervals[0][1] <= right:
                self.intervals = self.intervals[1:]
            if len(self.intervals) != 0 and left >= self.intervals[0][0]:
                tmp = self.intervals[0]
                self.intervals = self.intervals[1:]
                self.intervals.insert(0, [min(left, tmp[0]), max(right, tmp[1])])
            else:
                self.intervals.insert(0, [left, right])
        print(self.intervals)

        if i == j:
            if left > self.intervals[i][1]:
                self.intervals.insert(i + 1, [left, right])
            else:
                self.intervals[i][1] = max(right, self.intervals[j][1])
        elif left > self.intervals[i][1]:
            self.intervals = self.intervals[0 : i + 1] + [[left, max(right, self.intervals[j][1])]] + self.intervals[j + 1:]
        else:
            self.intervals = self.intervals[0 : i] + [[self.intervals[i][0], max(right, self.intervals[j][1])]] + self.intervals[j + 1:]

        return

    def count(self) -> int:
        ret = 0
        for x in self.intervals:
            ret += x[1] - x[0] + 1
        return ret


solu = CountIntervals()
solu.add(1, 3)
solu.add(2, 5)
print(solu.count())
solu.add(10, 20)
print(solu.count())
solu.add(4, 13)
print(solu.count())

solu = CountIntervals()
solu.add(2, 3)
solu.add(7, 10)
solu.add(2, 3)
solu.add(12, 15)
solu.add(16, 18)
print(solu.count())
solu.add(3, 20)
print(solu.count())


solu = CountIntervals()
solu.add(39, 44)
solu.add(13, 49)
print(solu.count())
solu.add(47, 50)
print(solu.count())

solu = CountIntervals()
solu.add(8, 43)
solu.add(13, 16)
print(solu.count())

solu = CountIntervals()
solu.add(33, 49)
solu.add(43, 47)
solu.add(37, 37)
solu.add(26, 38)
solu.add(11, 11)
print(solu.count())



