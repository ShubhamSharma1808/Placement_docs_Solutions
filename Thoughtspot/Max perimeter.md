Quesn:- 
https://imgur.com/a/pc4bGH7,https://imgur.com/a/pc4bGH7,
https://www.geeksforgeeks.org/maximum-perimeter-of-a-square-in-a-2d-grid/#:~:text=Given%20a%20matrix%20of%20integers,the%20sides%20of%20the%20square.

Approach:- 

- do extra matrix banane pdenge ek me row ka sum hoga ek me col. ka hoga.
- then fir nested loop hoga, 2 for loop se coordinate pta chlega which will be top-left corner of square(O(n^2)). and iske andr ek aur nested loop hoga 
  jo ki i and j dono ko increment krega till it is valid(O(n^3)). since it was square we were able to apply this loop to finc the bottom right corner . because in rect. case 
  i and j can be diff. so we would have needed two loop  then it would have been O(n^4).
- after getting top left and bottom right then we can get the perimeter sum from the two matrix.
