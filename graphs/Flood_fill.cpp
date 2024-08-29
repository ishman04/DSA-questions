#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int color,int initial){
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc]!=initial) return;
        image[sr][sc]=color;
        fill(image,sr-1,sc,color,initial);
        fill(image,sr+1,sc,color,initial);
        fill(image,sr,sc-1,color,initial);
        fill(image,sr,sc+1,color,initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color) fill(image,sr,sc,color,image[sr][sc]);   
        return image;
    }
};