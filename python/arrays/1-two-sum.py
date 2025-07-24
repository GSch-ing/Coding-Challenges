# LeetCode 1: Two Sum
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.
# Example 1:
# Input: nums = [1,2,3,6,11], target = 9
# Output: [2,3]
#
# https://leetcode.com/problems/two-sum/
#
#---------------------------------------
#
# La solucion utiliza un hash table (unordered_map en C++)
# Me muevo por el arreglo una unica vez y por cada elemento reviso si target menos el elemento actual resulta en algo existente en la tabla

from typing import List
    
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        n=len(nums)
        for i in range(n):
            complement = target - nums[i]
            if complement in seen:              # Verifico si esta en la hash table y si no lo esta, lo guardo en ella
                return [seen[complement], i]
            seen[nums[i]] = i
        return []       # Si no hay solucion

if __name__ == "__main__":
    # Ejemplo de prueba
    sol = Solution()
    resultado = sol.twoSum([3, 14, 28, 31, 45, 63, 94], 94)
    print("Resultado:", resultado)  # Deberia imprimir: Resultado: [3, 5]