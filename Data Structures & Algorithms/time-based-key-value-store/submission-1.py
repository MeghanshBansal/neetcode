class TimeMap:

    def __init__(self):
        self.hm = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.hm[key].append((timestamp, value))


    def get(self, key: str, timestamp: int) -> str:
        arr = self.hm[key]
        l, r = 0, len(arr) - 1
        while l <= r:
            mid = (l + r) // 2
            if arr[mid][0] == timestamp:
                return arr[mid][1]
            elif arr[mid][0] < timestamp:
                l = mid + 1
            else:
                r = mid - 1
        if l == 0:
            return ""
        return arr[l - 1][1]