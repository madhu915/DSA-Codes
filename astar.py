# -*- coding: utf-8 -*-
"""
Created on Tue Jun 21 11:23:42 2022

@author: HP
"""

def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

#GET HEURISTC VALUES

nodes=int(input("nodes: "))
H_dist=dict()
for i in range(nodes):
    n=str(input())
    heur=int(input())
    H_dist[n]=heur
#    print(H_dist)
        
''' H_dist = {	
'S': 15,	 	'B': 12,        'C': 11,        'D': 6,        
'E': 4,        'F': 11,        'G': 0    
}'''
    #return H_dist[n]

#GET GRAPH
    
Graph_nodes = dict()
edge=int(input("edgetot: "))
i=0
while (i<edge):
    vert=str(input())
    edgeli=list()
    sedge=int(input("edges: "))
    for j in range(sedge):
        n=str(input())
        cost=int(input())
        edgeli.append((n,cost))
        Graph_nodes[vert]=edgeli    
        i+=1
#print(Graph_nodes)

def a_star(start_node, stop_node):

    open_set = set(start_node)
    closed_set = set()
    
    g = {}               
    parents = {}        
    
    g[start_node] = 0
    parents[start_node] = start_node
    
    while len(open_set) > 0:
        n = None
    
        for v in open_set:
            if n == None or g[v] + H_dist[n] < g[n] + H_dist[n]:
                n = v
        
        if n == stop_node or Graph_nodes[n] == None:
            pass
        
        else:
            for (m, weight) in get_neighbors(n):

                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight

                else:
                    if g[m] > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n

                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
        if n == None:
            print('Path does not exist!')
            return None
        
        if n == stop_node:
            path = []

            while parents[n] != n:
                path.append(n)
                n = parents[n]

            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            print ('Weight found: ', g[m])

            return path

        open_set.remove(n)
        closed_set.add(n)
        
    print('Path does not exist!')
    return None

a_star('S', 'G')  
