class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0] ; 

        sort(times.begin() , times.end()) ; 

        int n = times.size() ; 

        priority_queue<int, vector<int>, greater<int>>pq ; 
        
        for (int i = 0; i < n ; i++) 
        pq.push(i) ; 

        priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int, int >>>pq1 ; 

        for(auto it : times) { 
            int arrival  = it[0] , dep= it[1] ; 

            while (!pq1.empty() && pq1.top().first <= arrival) { 
                 pair<int ,int>p = pq1.top() ; 
                 pq1.pop() ; 

                 pq.push(p.second) ; 

            }
            int chair = pq.top() ; 
            pq.pop() ; 

            pq1.push({dep , chair}) ; 

            if (arrival == target) 
            return chair; 

           
        }
return -1 ;
    }
};