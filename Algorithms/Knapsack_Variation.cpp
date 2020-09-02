 Q.)  Devide the given array in two equal parts so that absolute difference in sums of both the parts is minimum.

Soln:-
        dp[i][j][k] = dp[i-1][j][k] || dp[i-1][j-val[i]][k-1]
        Dp[i][j][k] denotes set with k elements with sum j till ith element and val[i] denotes value of ith element
