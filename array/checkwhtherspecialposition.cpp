
  #include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        map<int, int> colcheck;
        map<int, int> rowcheck;
        int specialPositions = 0;

        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
              
                    bool allZerosInRow = true;
                    for (int k = 0; k < mat[0].size(); ++k) {
                        if (k != j && mat[i][k] != 0) {
                            allZerosInRow = false;
                            break;
                        }
                    }

                    bool allZerosInCol = true;
                    for (int k = 0; k < mat.size(); ++k) {
                        if (k != i && mat[k][j] != 0) {
                            allZerosInCol = false;
                            break;
                        }
                    }

                    if (allZerosInRow && allZerosInCol) {
                        ++specialPositions;
                    }
                }
            }
        }

        return specialPositions;
    }
};