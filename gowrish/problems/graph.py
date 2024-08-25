class UnionFind:
    def _init_(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.size[root_x] > self.size[root_y]:
                self.parent[root_y] = root_x
                self.size[root_x] += self.size[root_y]
            else:
                self.parent[root_x] = root_y
                self.size[root_y] += self.size[root_x]

    def get_pairs(self):
        self.size.sort(reverse=True)
        fm = self.size[0]
        sm = self.size[1]
        if fm == self.size[1]:
            sm = self.size[2]
        if self.size.count(fm) > 1:
            n = self.size.count(fm)
            return n * (n - 1) // 2 * fm ** 2
        return fm * sm

def GetAnswer(N, P):
    if N == 1: return 0
    if N == 2: return 1
    uf = UnionFind(N)
    for u, v in enumerate(P):
        uf.union(u, v)
    return uf.get_pairs() % 1000000007