from queue import *
from typing import *

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = {}
        for i, equation in enumerate(equations):
            div = equation[0]
            divider = equation[1]
            consequence = values[i]
            ret = []
            if div not in graph:
                graph[div] = {}
            if divider not in graph:
                graph[divider] = {}
            graph[div][divider] = consequence
            graph[divider][div] = 1 / consequence

        for query in queries:
            cons = {}
            div = query[0]
            divider = query[1]
            if div not in graph or divider not in graph:
                ret.append(-1.0)
                continue
            cons[div] = 1.0
            Q = Queue()
            Q.put(div)
            while not Q.empty():
                vertex = Q.get()
                currval = cons[vertex]
                for k, v in graph[vertex].items():
                    if k not in cons:
                        cons[k] = currval * v
                        Q.put(k)
            ret.append(cons[divider] if divider in cons else -1.0)
        return ret


solution = Solution()
print(solution.calcEquation([["a", "b"], ["b", "c"]], [2.0, 3.0], [["a", "c"],["b", "a"],["a", "e"],["a", "a"],["x", "x"]]))
print(solution.calcEquation([["a","b"],["b","c"],["bc","cd"]], [1.5,2.5,5.0], [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]))