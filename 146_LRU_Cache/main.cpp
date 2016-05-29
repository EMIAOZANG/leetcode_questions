#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache{
public:
    
    LRUCache(int capacity):max_capacity(capacity) {
    }
    
    int get(int key) {
    //pick up values mapped to key and place it at the top of the mem queue
        if (index.find(key) == index.end()) {
            return -1;
        }
        auto it = index.find(key);
        int tmp_val = (it -> second) -> second;
        move_to_front(it -> second);
        return tmp_val;
    }
    
    void set(int key, int value) {
        //Simple logic here,
        //First check if the key already exists, if so, we just modify the node
        //Otherwise, we pop the back of the list (least recently used) out, then insert a new node at front
        auto it = index.find(key);
        if (it != index.end()) {
            it -> second -> second = value; //reset the value
            move_to_front(it -> second);
        }
        else {
            if (mem_data.size() >= max_capacity) {
                index.erase(mem_data.rbegin() -> first);
                mem_data.pop_back();
            }
            
            mem_data.push_front(make_pair(key, value));
            //create record in index
            index.insert(make_pair(key, mem_data.begin()));
        }
    }
    
private:
    typedef list<pair<int, int> > PList;
    PList mem_data;
    unordered_map<int, PList::iterator> index;
    int max_capacity;

    void move_to_front(PList::iterator& it){
      if (it != mem_data.begin() ){
        mem_data.splice(mem_data.begin(), mem_data, it);
      }
    }
    
};

int main(){
  LRUCache lc(2);
  lc.set(2,1);
  lc.set(2,2);
  cout << lc.get(2) << endl;
  lc.set(1,1);
  lc.set(4,1);
  cout << lc.get(2) << endl;
  return 0;
}
