class uf:
    def __init__(self,n) -> None:
        self.p = list(range(n))
        self.sz = [1]*n
    def find(self,x):
        if self.p[x]!=x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    def union(self,x,y):
        a,b = self.find(x),self.find(y)
        if a != b:
            if self.sz[a] > self.sz[b]:
                self.p[b] = a
                self.sz[a] += self.sz[b]
            else:
                self.p[a] = b
                self.sz[b] += self.sz[a]