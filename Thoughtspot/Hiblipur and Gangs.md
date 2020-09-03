Quesn:- https://i.imgur.com/oTCgyaJ.png, https://imgur.com/a/pc4bGH7

Approach:- 

- jo 2 set given hai uski pehle size nikal lo kitne vertex hai graph me then un dono ka complete graph ki no. of 
  edges calculate krlo N = n(n-1)/2. 
- now, given edges subtract krdo from N for both the gangs. lets say we get N_1 and N_2.
- now, from total members subtract the size of both the gangs, so that we can find the vertex which are reamining.
- this no. of vertex will be multiplied by the size of the set which is bigger so that no. of edges will be max.
- add the end sum up N_1 + N_2 + max(size(set1),size(set2))*remaining vertex. 
