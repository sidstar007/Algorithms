/* This is my solution for LeetCode problem 1483,
   solving this problem efficiently (in O(logn)) requires
   the use of a technique called 'Binary Lifting',
   where in we store ancestors in powers of 2
*/


class TreeAncestor {
    vector<vector<int>> logParent; // Store ancester of node at power of two postions above it.
    int LOG = 0; // Max power of two within n (number of nodes).

public:
    TreeAncestor(int n, vector<int>& parent) {
        // Incrementing value of LOG until pow(2, LOG) is within n
        while ((1 << LOG) <= n) {
            LOG++;
        }
        logParent = vector<vector<int>>(n, vector<int>(LOG, -1));

        for (int v=0; v<n; ++v) {
            logParent[v][0] = parent[v];
        }

        for (int j=1; j<LOG; ++j) {
            for (int v=0; v<n; ++v) {
                if (logParent[v][j-1] != -1) {
                    logParent[v][j] = logParent[logParent[v][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

        for (int j=0; j<LOG; ++j) {
            /* Iterating k in its binary form eg,
               17 = 10001;
               when j = 0: (10001 & 00001) = 1,
               so the node is replaced by it's 1st ancester,
               similarly when j = 4, node (the parent of original node),
               is replaced by it's 16th ancester (which is the original node's 17th ancester)
            */ 
            if (k & (1 << j)) {
                node = logParent[node][j];
                if (node == -1) return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
