Quesn:- https://i.imgur.com/oTCgyaJ.png, https://imgur.com/a/pc4bGH7

Approach:- 

- jo 2 set given hai uski pehle size nikal lo kitne vertex hai graph me then un dono ka complete graph ki no. of 
  edges calculate krlo N = n(n-1)/2. 
- now, given edges subtract krdo from N for both the gangs. lets say we get N_1 and N_2.
- now, from total members subtract the size of both the gangs, so that we can find the vertex which are reamining.but in this there is one more condition that you     can get a component other than those two which may be connected by an edge.
- this no. of vertex will be multiplied by the size of the set which is bigger so that no. of edges will be max.
- add the end sum up N_1 + N_2 + max(size(set1),size(set2))*remaining vertex. 

=> basically you will have a vector of pair which will store the no. edges and vertex of each component and you can also store in this that this compo. had gang        leader d or e or other , or you can have another vector mapping each vertex with its component no., this components can be find out by simple dfs traversal. 
