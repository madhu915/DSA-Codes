# -*- coding: utf-8 -*-
"""
Created on Tue Jun 21 10:04:51 2022

@author: HP
"""

que = list()
visited = list()
path = dict()

j1 = 4
j2 = 3
target = 2

def visit(visited,x,y):
    if(len(visited) == 0):
        return True
    for i,j in visited:
        if(x == i and y == j):
            return False
    return True

def conditions(x,y):
    #fill by pump
    if(y < 3):
        if(visit(visited,x,3)):
            que.append((x,3))
            path[(x,3)] = (x,y)
    if(x < 4):
        if(visit(visited,4,y)):
            que.append((4,y))
            path[(4,y)] = (x,y)
    #empty on grnd
    if(x > 0):
        if(visit(visited,0,y)):
            que.append((0,y))
            path[(0,y)] = (x,y)
    if(y > 0):
        if(visit(visited,x,0)):
            que.append((x,0))
            path[(x,0)] = (x,y)
    #transfer x --> y
    if(x>0 and y<3):
        if(x+y > 3):
            if(visit(visited,abs(3-(x+y)), 3)):
                que.append(( abs(3-(x+y)), 3 ))
                path[( abs(3-(x+y)), 3 )] = (x,y)
        else:
            if(visit(visited,0, x+y)):
                que.append((0,x+y))
                path[(0,x+y)] = (x,y)
    #transfer y --> x
    if(x<4 and y>0):
        if(x+y > 4):
            if(visit(visited,4, abs(4-(x+y)))):
                que.append(( 4, abs(4-(x+y)) ))
                path[( 4, abs(4-(x+y)) )] = (x,y)
        else:
            if(visit(visited,x+y, 0)):
                que.append((x+y,0))
                path[(x+y,0)] = (x,y)

def print_path(x,y):
    if(x == 0 and y == 0):
        return
    a,b = path[(x,y)]
    print_path(a,b)
    print(a ,b)

def bfs():
    que.append((0,0))
    while(len(que) != 0):
        x,y = que[0]
        visited.append((x,y))
        conditions(x,y)
        if(x == target):
            print_path(x,y)
            # print(que)
            # print(path)
            break
        que.pop(0)


if __name__ == "__main__":
    print( "bfs for the water Jug problem :: ")
    bfs()
