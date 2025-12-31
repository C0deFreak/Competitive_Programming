class Solution:

    def encode(self, strs: list[str]) -> str:
        s = ''
        for i in strs:
            s += f'{len(i)}#{i}'
        
        return s

    def decode(self, s: str) -> list[str]:
        strs = []

        i = 0
        while i < len(s):
            a = ''
            while s[i] != '#':
                a += s[i]
                i += 1

            i += 1
            strs.append(s[i:i+int(a)])
            i += int(a)
            
        
        return strs