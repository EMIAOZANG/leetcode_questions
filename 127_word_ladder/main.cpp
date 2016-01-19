//Be EXTREMELY careful with this question
//Basic idea:
//  Edit Distance checking + BFS
//
//Take Care:
//1. The length of the transformation is the number of words on this transformation (including begin and end)
//2. DO NOT check items in wordList one by one, the list might be VERY VERY long, instead, construct adjacent words by enumerating from 'a' to 'z' on each digit of current string, this will only cause 26*len(word) time
//
//Time complexity: O(|V|+|E|)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
    
    bool one_edit_distance(string a, string b){
        int sum = 0;
        for (int i = 0; i < a.length(); i++){
            sum += int(a[i] != b[i]);
            if (sum > 1){
                return false;
            }
        }
        return (sum == 1);
    }
    
    int BFS(string beginWord, string endWord, unordered_set<string>& wordList){
        //Slow version, got TLE
        int dist = 0;
        unordered_set<string> unvisited_list(wordList);
        queue<pair<string,int> > q;
        
        if (wordList.size() == 0){
            return 0;
        }
        
        q.push(make_pair(beginWord,0));
        
        while (!q.empty()){
            string word_from = q.front().first;
            dist = q.front().second;
            q.pop();
            
            //probably need to check !wordfrom == beginWord
            if (dist > 0 && one_edit_distance(word_from,endWord)){
                return dist+1;
            }
            unordered_set<string>::iterator it;
            for (it = unvisited_list.begin(); it != unvisited_list.end();){
                string word_to = *(it);
                if (one_edit_distance(word_from,word_to)){
                    unvisited_list.erase(it++);
                    q.push(make_pair(word_to,dist+1));
                }
                else {
                    ++it;
                }
            }
        }
        return 0;
        
    }
    
    int BFS_enum(string beginWord, string endWord, unordered_set<string>& wordList){
        int dist = 0;
        unordered_set<string> unvisited_list(wordList);
        unordered_set<string>::iterator it;
        queue<pair<string,int> > q;
        string new_word;
        
        if (wordList.size() == 0){
            return 0;
        }
        
        q.push(make_pair(beginWord,1));
        
        while (!q.empty()){
            string word_from = q.front().first;
            dist = q.front().second;
            q.pop();
            
            if (dist > 0 && one_edit_distance(word_from,endWord)){
                return dist+1;
            }
            
            for (int idx = 0; idx < endWord.length(); idx++){
                new_word = word_from;
                for (int i = 0; i < 26; i++){       //consider the fact that wordList might be very long (much longer than max_word_length*26), here we enumerate 'a' to 'z' on each digit to construct words and check if they are in the list, rather than checking list items one by one, which would obviously take longer time when the wordList is very long
                    new_word[idx] = char('a'+i);
                    it = unvisited_list.find(new_word);
                    if (it != unvisited_list.end()){
                        unvisited_list.erase(it);
                        q.push(make_pair(new_word,dist+1));
                    }
                    
                }
            }
        }
        return 0;
        
    }
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        return BFS_enum(beginWord, endWord, wordList);
    }
};

int main(){
    Solution sls;
    string b = "hot";
    string e = "dog";
    unordered_set<string> s ( {"hot","dog","dot"} );
//    string b = "";
//    string e = "";
//    unordered_set<string> s ( {} );
    cout << sls.ladderLength(b,e,s);
    return 0;
}


