/*
 * https://leetcode.com/problems/daily-temperatures/
 * 
 * The key is to identify that the indexes are the distances between the temps
 * 
 * 
 * We create ans stack of max temps, nad iterate form the upper limit if the
 * stack is empty no othe rtem is hiher, else keep removing elements of the
 * stack until we find the higher them, get the index distance and add the
 * current temp to the stack
 * 
 */

#include <iostream>
#include <utility>
#include <stack>

using std::cout;
using std::endl;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int vector_size = temperatures.size();
        vector <int> ans (vector_size,0);
        vector <pair<int,int>> lstack {};
        //We know the max this stack will grow
        // lstack.resize(vector_size >> 1);
        lstack.push_back({temperatures[vector_size-1],vector_size-1});
        for(int i = vector_size -2; i >= 0 ; i--)
        {
            //Look for a higer temperature
            while(!lstack.empty())
            {
                //the temp in the stack is colder
                if(lstack.back().first <= temperatures[i])
                {
                    lstack.pop_back();
                }
                else{
                    //found a higher temperature
                    ans[i] = lstack.back().second -i;
                    break;
                }
            }
            lstack.push_back({temperatures[i],i});
        }

        return ans;
    }

};