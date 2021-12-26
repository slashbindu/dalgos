/*Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
*/
typedef vector<int> Iterval;
using namespace std;

class  Solution {
            
        public:
    
            int minMeetingRooms(vector<vector<int>>& intervals) {
        
            int n_mtgs = intervals.size();
            if(!n_mtgs) {
                return 0;
            }

            // sort intervals arr by start-time
            auto mysort =  [](vector<int> a, vector<int> b){ return( a[0] < b[0]);};
                                 
            sort(intervals.begin(), intervals.end(), mysort);

            // min-heap by nearest  endtime
            priority_queue<int, vector<int>, greater<int>> pq_endtime;     
            
            //allocate first meeting 
            pq_endtime.push(intervals[0][1]);
            int mtgroom = 1;
                
            for(int i = 1; i < intervals.size(); i++){

                //is start_time before the end_Time ? we need a room,
                if(intervals[i][0] < pq_endtime.top()) {
                    mtgroom++;
                    pq_endtime.push(intervals[i][1]); //store end time
                }  else {
                    //re-use the room and add endtime
                    pq_endtime.pop();
                    pq_endtime.push(intervals[i][1]);

                }
                            
             }
             return mtgroom;
       }

        
  
};
