class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* question asan h bas observation skill chahiye
        matrix ko observe karo aur dekho ki element @ mat[0][m-1] ke left em saare decreasing hain
        aur downward saare increasing (binary search range mil gayi) ab simultaneously rows 
        aur columns ko remove karte jao target find karne k liye
        same observe karo aur dekho ki matrix[n-1][0] k liye bhi ye condition sahi baithi h lekin
        matrix[0][0] aur matrix[n-1][m-1] k liye nhi h.
        */
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col] == target)return 1;
            else if(matrix[row][col] > target){
                col--;
                // usse chota h to uss col me bhi nhi hoga 
            }
            else row++; // similarly row eliminate kardo
        }
        return 0;
        //  TC -> O(m+n).
    }
};