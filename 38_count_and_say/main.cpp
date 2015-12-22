//Usage of std::to_string can make int to string simpler

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      string start = "1";
      int count = 0;
      char curr_num = start[0];
      string count_n_say = "";

      for ( int i = 1; i < n; i++ ){
        curr_num = start[0];
        count_n_say = "";
        count = 0;
        for ( int j = 0; j < start.length(); j++ ){
          if ( start[j] != curr_num ){
            count_n_say += std::to_string(count); 
            count_n_say += curr_num;

            curr_num = start[j];
            count = 0;
          }
          count++;
        //Replace string with the new one and restart iteration

        }
        count_n_say += std::to_string(count);
        count_n_say += curr_num;
        //update start and restart
        start = count_n_say;
      }
      return start; 
    }
};

int main(){
  Solution s;
  cout << s.countAndSay(5) << endl;
  return 0;
}
