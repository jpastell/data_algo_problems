
/*
 * https://leetcode.com/problems/validate-binary-search-tree/
 * in order gives you and ordered stack current element it alwasy has to be bigger than the previos
 * 
 */

#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //inorder iteration
        bool do_pop = false;
        stack<TreeNode*> in_stack;
        in_stack.push(root);
        int counter  = 0;
        int value = 0;
        TreeNode* temp;
        while(!in_stack.empty())
        {
            temp = in_stack.top();
            if(do_pop)
            {
                in_stack.pop();
                counter++;
                if(counter == k)break;
                if(temp->right)
                {
                    in_stack.push(temp->right);
                    do_pop = false;
                }
            }
            else
            {
                if(temp->left)in_stack.push(temp->left);
                else do_pop = true;
            }
        }
        return temp->val;
    }
};