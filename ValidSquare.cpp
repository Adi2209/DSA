class Solution {
public:
    int sd(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        int sd0, sd1, sd2, sd3;
        vector<vector<int>> pts = {p1, p2, p3, p4};
        sort(begin(pts), end(pts));
        // computing the distances between ordered points
        sd0 = sd(pts[0], pts[1]), sd1 = sd(pts[0], pts[2]), sd2 = sd(pts[0], pts[3]), sd3 = sd(pts[1], pts[2]);
        // checking if sides are non-0 and if sides and diagonals are equal
        return sd0 && sd2 && sd0 == sd1 && sd2 == sd3;
    }
};