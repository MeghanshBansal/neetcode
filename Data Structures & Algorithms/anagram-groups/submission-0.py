class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        dictionary = dict()


        for i in strs:
            temp = i
            sorted_i = ''.join(sorted(temp))
            if dictionary.get(sorted_i) != None:
                dictionary[sorted_i].append(i)
            else: 
                dictionary[sorted_i] = [i]

        for v in dictionary.values():
            ans.append(v)
        
        return ans