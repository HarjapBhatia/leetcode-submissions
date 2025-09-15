class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        cnt = 0
        for w in words:
            for c in w:
                if c in brokenLetters: 
                    cnt += 1
                    break
        return len(words)-cnt
