class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n =  events.size() ; 
        int m =  events[0].size() ;
        int  cnt = 0 ; 
         priority_queue<pair<int ,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq ; 

         sort(events.begin() , events.end()) ; 

         int maxval = 0 , maxsum = 0 ; 

         for(auto& it : events)  {

            while (pq.size() &&  pq.top().first < it[0]) { 
                 maxval = max(maxval , pq.top().second) ; 
                 pq.pop() ; 
            }
            maxsum = max(maxsum , maxval + it[2]) ; 
            pq.push({it[1] , it[2]}) ; 


         }
         return maxsum ; 
    }
};