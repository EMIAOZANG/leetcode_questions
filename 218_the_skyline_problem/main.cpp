/*
 * Scan Line Method:
 * 
 * 1. sort the event (building startpoint, building endpoint) by timestamp in ascending order
 *    Trick here: Inorder to track the starting point from ending point for each building, we set the endpoint as (timestamp, -height), so we only need to find -second_element when we get a endpoint to get its correspoding starting point,
 * 2. Use a HashHeap or Multiset to maintain a maxQueue of heights at current time
 * 3. process the event queue by timestamp, at each time stamp, process all events occured
 *    1) if startpoint: add the height to the queue
 *    2) if endpoint: find the corresponding startpoint, remove it from the maxQueue
 * 4. After all events are processed, append (timestamp, max(maxQueue)) to the result list
 *
 * NOTE: after processing all events with the same timestamp, when the maxQueue is empty, we have to output a (timestamp 0) to indicate the end of the skyline section
 */
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
      multimap<int,int> points;
      multiset<int> currentList;
      vector<pair<int,int> > result;
      int currHeight = 0;
      if (buildings.size() == 0){
        return result;
      }
      for (int i = 0; i < buildings.size(); i++){
        points.insert(make_pair(buildings[i][0], buildings[i][2]));
        points.insert(make_pair(buildings[i][1], 0-buildings[i][2]));
      }
      auto map_it = points.begin();
      auto set_it = currentList.begin();
      auto next_it = points.upper_bound(map_it->first); //get the starting point at next tik
      while (map_it != points.end()){
        //process all events at the same timestamp
        int timestamp = map_it->first;
        while (map_it != next_it){
          if (map_it->second < 0){
            set_it = currentList.find(0-(map_it->second));
            if (set_it != currentList.end()){
              currentList.erase(set_it); //erase the start point of the same building
            }
          }
          else {
            currentList.insert(map_it->second);
          }
          map_it++;
        }
        //output the max value in currentList
        if (!currentList.empty() && (result.empty() || (result.rbegin())->second != *(currentList.rbegin()))) {
          result.push_back(make_pair(timestamp, *(currentList.rbegin())));
        }
        else if (currentList.empty()){
          result.push_back(make_pair(timestamp, 0));
        }
        next_it = points.upper_bound(map_it->first); //move to the next timestamp
      }
      return result;
    }
};

//[(0,3),(2,-3),(2,3),(5,-3)]
int main(){
  return 0;
}
