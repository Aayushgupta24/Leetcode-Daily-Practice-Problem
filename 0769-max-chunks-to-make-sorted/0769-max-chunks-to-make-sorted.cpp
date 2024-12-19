class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ; 

         stack<int>st ; 

         for(int it : arr) { 
             
             if (!st.empty() &&  it < st.top()) { 
                 int top =  st.top() ; 

                 while (!st.empty() && it < st.top()) 
                 st.pop() ; 

                 st.push(top) ; 

             }
             else 
              st.push(it) ; 
         } 
         return st.size() ; 
    }
};