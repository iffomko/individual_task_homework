#include <iostream>

void print(uint32_t bitArray, int n) {
    for (int i = 0; i < n; i++)
        if (bitArray & (1 << i))
            std::cout << i << " ";
}

int main() {
    int n, k, count = 0;
    uint32_t res = 0;

    std::cout << "Enter size of set: ";
    std::cin >> n;

    std::cout << "Enter size of subset: ";
    std::cin >> k;

    for (int i = 0; i < k; i++)
        res |= (1 << i);

    int i;

    while (res < (1 << n)) {
        if (count == 0) {
            // Creating set of numbers for all set of size k

            uint32_t numSet = 0;

            for (int j = 0; j < n; j++)
                if (res & (1 << j)) {
                    int x = j;

                    while (x > 0) {
                        numSet |= (1 << (x % 10));
                        x /= 10;
                    }

                    break;
                }

            // Checking for full set intersection of number everything number from set size k

            bool isEqualSets = true;

            for (int j = 0; j < n; j++)
                if (res & (1 << j)) {
                    int x = j;

                    uint32_t tempSet = 0;

                    while (x > 0) {
                        tempSet |= (1 << (x % 10));
                        x /= 10;
                    }

                    if (tempSet != numSet) {
                        isEqualSets = false;
                        break;
                    }
                }

            // print numbers of set

            if (isEqualSets) {
                std::cout << "{ ";
                print(res, n);
                std::cout << "}\n";
            }

            // Delete numbers in set and right shift

            i = 0;

            while (count == 0) {
                while (res & (1 << i)) {
                    res ^= (1 << i);
                    count++;
                    i++;
                }

                if (count == 0)
                    i++;
            }

            res |= (1 << i);
            count--;
        } else { // Add numbers in the set
            i = 0;

            while (count != 0) {
                res |= (1 << i);
                count--;
                i++;
            }
        }
    }

    return 0;
}
