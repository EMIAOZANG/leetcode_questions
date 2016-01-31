//
//  main.cpp
//  hckcontest
//
//  Created by Lu Christopher on 1/29/16.
//  Copyright © 2016 Lu Christopher. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class MasterNode{
public:
    unordered_map<int, unordered_set<int> > pList;
    vector<int> dcList;
    
    void addDataCenter(int dcId, vector<int>& dc){
        for (int i = 0; i < dc.size(); i++){
            if (pList.find(dc[i]) == pList.end()){
                unordered_set<int> ndc;
                ndc.insert(dcId);
                pList.insert(make_pair(dc[i],ndc));
                for (auto it = dcList.begin(); it != dcList.end(); it++){
                    //propagate new item to all existing data centers
                    if ((*it) != dcId){
                        cout << dc[i] << " " << dcId << " " << (*it) << endl;
                        ((pList.find(dc[i]))->second).insert((*it));
                    }
                }
            }
            else{
                //append data center Id to existing list
                ((pList.find(dc[i]))->second).insert(dcId);
            }
        }
        dcList.push_back(dcId);
        for (auto it = pList.begin(); it != pList.end(); it++){
            if ((it->second).find(dcId) == (it->second).end()){
                cout << it->first << " " << *((it->second).begin()) << " " << dcId << endl;
                (it->second).insert(dcId);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    MasterNode ms;
    int N = 0;
    cin >> N;
    vector<int> data;
    int m = 0;
    for (int i = 0; i < N; i++){
        cin >> m;
        data.clear();
        for (int j = 0; j < m; j++){
            int dataId;
            cin >> dataId;
            data.push_back(dataId);
        }
        ms.addDataCenter(i+1, data);
    }
    return 0;
}
