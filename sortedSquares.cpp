#include <vector>
#include <limits>
#include <iostream>

/**
 * Return the sorted squares of a list of sorted numbers
 */
std::vector<int> sortedSquares(std::vector<int> &nums) {
    std::vector<int> output(nums.size() + 1, 0);
    output[nums.size()] = std::numeric_limits<int>::max();
    int start = 0;
    int end = nums.size();

    for (int num: nums) {
        int square = num * num;

        if (num < 0) {
            end--;
            output[end] = square;
        } else {
            while (square > output[end]) {
                output[start] = output[end];
                end++;
                start++;
            }

            output[start] = square;
            start++;
        }
    }

    output.pop_back();

    return output;
}

int main() {
    std::vector<int> nums{-4, -1, 0, 3, 10};
    std::vector<int> squares = sortedSquares(nums);
    
    for (int square: squares)
        std::cout << square << ',';
}