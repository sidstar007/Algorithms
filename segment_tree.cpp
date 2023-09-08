#include <bits/stdc++.h>
using namespace std;

int N = 1e5;
vector<int> nums(N);
vector<int> tree(4*N);

// function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = nums[start];
        return;
    }

    int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

// query on a segment tree
int query(int node, int start, int end, int low, int high) {
    if (start > high || end < low) {
        return 0;
    }

    if (start >= low && end <= high) {
        return tree[node];
    }

    int mid = (start + end)/2;
    int q1 = query(2*node, start, mid, low, high);
    int q2 = query(2*node + 1, mid + 1, end, low, high);

    return q1 + q2;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i=0; i<n; ++i) {
        cin >> nums[i];
    }

    // building segment tree (1 indexed)
    build(1, 0, n-1);
    for (int i=1; i<15; ++i) {
        cout << tree[i] << " ";
    }

    while (1) {
        int op;
        cout << "\nEnter\n-1: For exit\n1: For Query\n";
        cin >> op;

        if (op == -1) break;

        else if (op == 1) {
            int low, high;
            cout << "Enter start and end index: ";
            cin >> low >> high;
            cout << "Sum: " << query(1, 0, n-1, low, high) << endl;
        }
    }

    return 0;
}

