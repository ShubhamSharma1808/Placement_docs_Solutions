/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 TreeNode* traverse(vector<int> &v, int strt, int end){
     
     if(strt>end)
        return NULL;
     TreeNode* root; 
     if(strt==end)
        return root = new TreeNode(v[strt]);
         
     int mid = (strt + end)/2;
     root = new TreeNode(v[mid]);
     root->left = traverse(v,strt,mid-1);
     root->right = traverse(v, mid+1,end);
     return root;
 }
 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> v;
    while(A!=NULL){
        v.push_back(A->val);
        A = A->next;
    }
    
    return traverse(v,0,v.size()-1);
}



/* 
Comment on the question:- 
  LL me se array me dal liya. then divide and conquer lga diya , middle uthaya use root me dla 
  fir uska left part array ke left subtree ke liye and right subpart of array  right subtree ke liye
  and aise ye procedure repeat hoti rhegi
*/








