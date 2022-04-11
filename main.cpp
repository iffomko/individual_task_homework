#include <iostream>

int main() {
    int n, k, res = 0, count = 0;

    std::cout << "Enter size of set: ";
    std::cin >> n;

    std::cout << "Enter size of subset: ";
    std::cin >> k;

    for (int i = 0; i < k; i++)
        res |= (1 << i);

    int i;

    while (res < (1 << n)) {
        if (count == 0) {
            std::cout << "{ ";
            for (int j = 0; j < n; j++)
                if (res & (1 << j))
                    std::cout << j << " ";
            std::cout << "}\n";

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
        } else {
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
