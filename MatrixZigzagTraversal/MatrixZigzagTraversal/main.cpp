//
//  main.cpp
//  MatrixZigzagTraversal
//
//  Created by Wei Hainan on 2017/10/26.
//  Copyright © 2017年 kuandeng. All rights reserved.
//

#include <vector>

using namespace std;
#include <iostream>


class Solution {
public:
    /*
     * @param matrix: An array of integers
     * @return: An array of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool isRight = true;
        int i=0, j=0;
        while( i<row || j<col ) {
            printf("%d", matrix[i][j]);
            result.push_back(matrix[i][j]);
            if(isRight){
                if(i==0){
                    if(j==row-1){
                        isRight = false;
                        i--;
                    }else{
                        j++;
                    }
                }else{
                    if(j==row-1){
                        isRight = !isRight;
                        i--;
                    }else{
                        i--;
                        j++;
                    }
                }
            }else{
                if(j==0){
                    if(i==row-1){
                        isRight = true;
                        i--;
                        j++;
                    }else{
                        i++;
                    }
                }else{
                    if(i==row-1){
                        isRight = true;
                        j++;
                    }else{
                        i++;
                        j--;
                    }
                }
            }
        }
        
        return result;
    }
};


void printResult(const vector<int> & input){
    for(int i=0; i<input.size(); ++i){
        cout<<input[i]<<" "<<endl;
    }
}

void printInput(const vector<vector<int>> & input){
    int row = input.size();
    int col = input[0].size();
    for(int i=0; i<row; ++i){
        for (int j=0; j<col; ++j) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> input;
    int num = 1;
    int row = 3;
    int col = 4;
    for (int i=0; i<row; ++i) {
        vector<int> tmp;
        for (int j=0 ; j<col; ++j) {
            tmp.push_back(num++);
        }
        input.push_back(tmp);
    }
    
    printInput(input);
    
    
    Solution solution;
    printResult(solution.printZMatrix(input));
    
    return 0;
}
