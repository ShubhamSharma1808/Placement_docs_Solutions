Q. 3  Given an array of integers A, find out the maximum no. of partitions you can make such that if you sort each partition, and then concatenate them, the array becomes sorted.
      (https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)
Two approaches:- 
- ek to ye ki left max and right min dekho agr left max<= right min hai to partition hoga and count bda do O(n)
- Dusra ye ki jo given array hai use sort krlo and hrr index pe sum check kro dono array ka agr equal hai to partition bnado. O(nlogn)
