// =====================================================================================
//
//       Filename:  ca2clq.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  07/27/15 10:09:28
//       Revision:  none
//       Compiler:  g++ (clang)
//
//         Author:  |Zhiwen Fang| (), |zhiwenf@gmail.com|
//   Organization:  
//
// =====================================================================================

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <ctime>

using namespace std;

int main ( int argc, char *argv[] )
{
  int num, con;
  string line;
  getline(cin, line);
  stringstream ss(line);
  ss >> num >> con;
  vector<pair<double, vector<int> > > ca;
  for (int i = 0; i < con; ++i) {
    getline(cin, line);
    stringstream ss(line);
    double weight;
    vector<int> tmp;
    ss >> weight;
    int item;
    while (ss >> item) tmp.push_back(item);
    sort(tmp.begin(), tmp.end());
    ca.emplace_back(weight, tmp);
  }
  vector<vector<bool> > adj( con, vector<bool>(con, true));
  int e = con * (con-1) / 2;
  for (int i = 0; i < con; ++i) {
    for (int j = 0; j < con; ++j) {
      int k1 = 0, k2 = 0;
      while ( adj[i][j] && k1 < ca[i].second.size() && k2 < ca[j].second.size()) {
        if (ca[i].second[k1] == ca[j].second[k2]) {
          adj[i][j] = adj[j][i] = false;
          --e;
          ++k1;
          ++k2;
        } else if (ca[i].second[k1] < ca[j].second[k2]) ++k1;
        else ++k2;
      }
    }
  }
  cout << "p edges " << con << " " << e << endl;
  for (int i = 0; i < con; ++i) {
    cout << "n " << i+1 << " " << int(ca[i].first * 1000) << endl;
  }
  for (int i = 0; i < con; ++i) {
    for (int j = i+1; j < con; ++j) {
      if (adj[i][j]) cout << "e " << j+1 << " " << i+1 << endl;
    }
  }
  return EXIT_SUCCESS;
}				
// ----------  end of function main  ----------
