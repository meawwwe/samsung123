class Solution:
    def validSquare(self, p1, p2, p3, p4):
        if p1==p2==p3==p4:
            return False
        dis = []
        poss = [p1,p2,p3,p4]
        for i in range(4):
            for j in range(i):
                dis.append(self.dist(poss[i],poss[j]))
        dis.sort()
        if dis[0]*2==dis[-1]:
            if dis[0]==dis[1]==dis[2]==dis[3]:
                if dis[4]==dis[5]:
                    return True
        return False
    
    def dist(self,pos1,pos2):
        return (pos1[0]-pos2[0])**2+(pos1[1]-pos2[1])**2
        
