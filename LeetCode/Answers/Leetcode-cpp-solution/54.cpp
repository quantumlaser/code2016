/*
Spiral MatrixMar 25 '124111 / 14949

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/

2
	

@1337c0d3r How about my iterative solution (which is more elegant, more efficient, and also eliminates potential stack overflow) :-)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        ssize_t beginX = 0, endX = matrix[0].size() - 1;
        ssize_t beginY = 0, endY = matrix.size() - 1;
        while (true) {
            // From left to right
            for (ssize_t i = beginX; i <= endX; ++i)
                result.push_back(matrix[beginY][i]);
            if (++beginY > endY) break;
            // From top down
            for (ssize_t i = beginY; i <= endY; ++i)
                result.push_back(matrix[i][endX]);
            if (beginX > --endX) break;
            // From right to left
            for (ssize_t i = endX; i >= beginX; --i)
                result.push_back(matrix[endY][i]);
            if (beginY > --endY) break;
            // From bottom up
            for (ssize_t i = endY; i >= beginY; --i)
                result.push_back(matrix[i][beginX]);
            if (++beginX > endX) break;
        }
        return result;
    }
};

link

answered 12 Jan, 01:39
Lu-An%20Gong's gravatar image

Lu-An Gong
318●4●6
accept rate: 7%

edited 28 May, 12:36

Yes, your iterative solution is indeed more elegant and efficient. However, if I were you, I would avoid having a while (true) and break statements unless necessary. It seemed that you could have returned the result straight away rather than breaking out of the loop.
(12 Jan, 13:12) 1337c0d3r ♦♦ 1337c0d3r's gravatar image

@1337c0d3r Great! I didn’t think of that. Thanks.
(12 Jan, 19:42) Lu-An Gong Lu-An%20Gong's gravatar image

@Lu-An Gong: Great picture! A picture is always worth a thousand words :)