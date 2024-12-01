class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>sett ; 

        for (int it : arr) { 
             
             if(sett.count(2*it) || (it%2 == 0 &&sett.count(it/2))) 
             return true ; 

             sett.insert(it) ; 
        }
        return false ;
    }
};