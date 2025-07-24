// LeetCode 1: Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [1,2,3,6,11], target = 9
// Output: [2,3]
//
// https://leetcode.com/problems/two-sum/
//
//---------------------------------------
//
// La solucion utiliza un hash table (unordered_map en C++)
// Me muevo por el arreglo una unica vez y por cada elemento reviso si target menos el elemento actual resulta en algo existente en la tabla

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            if (seen.count(complement))     // Verifico si complement esta en el mapa. Al ser un mapa puede estar 1 o 0 veces, devolviendo estos posibles valores
            {                               // En bool, count es true si aparece y false si no aparece
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};      // Si no hay solucion
    }
};

int main() {
    // Ejemplo de prueba
    Solution sol;
    vector<int> nums = {2,7,11,15};
    vector<int> result = sol.twoSum(nums, 9);
    cout << "Resultado: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}