#include <iostream>
#include <vector>
#include <numeric>

// Fenwick tree (Binary Indexed Tree) implementation
class FenwickTree {
private:
    std::vector<int> bit;
    int size;

public:
    FenwickTree(int s) : size(s), bit(s + 1, 0) {}

    // Add a value to an index
    void update(int idx, int delta) {
        for (++idx; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    // Get prefix sum up to an index
    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Find the k-th set bit (k-th present child)
    int findKth(int k) {
        int low = 0, high = size - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (query(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long k;
    std::cin >> n >> k;

    FenwickTree ft(n);
    // Initialize Fenwick tree: all children are present
    for (int i = 0; i < n; ++i) {
        ft.update(i, 1);
    }

    long long current_pos = 0; // Current position in the circle (0-indexed)

    for (int i = 0; i < n; ++i) {
        long long remaining_children = n - i;

        // Calculate the next position to remove
        // (k % remaining_children) handles cases where k is very large
        current_pos = (current_pos + k) % remaining_children;

        // Find the actual index of the child to remove
        // We add 1 to current_pos because findKth expects 1-indexed count
        int removed_idx = ft.findKth(current_pos + 1);

        // Print the child number (1-indexed)
        std::cout << removed_idx + 1 << (i == n - 1 ? "" : " ");

        // Mark the child as removed in the Fenwick tree
        ft.update(removed_idx, -1);
    }
    std::cout << std::endl;

    return 0;
}
