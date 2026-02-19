class Solution:

    def backtrack(self, answer: List[str], current: List[str], openCount: int, closeCount: int, n: int) -> None:
        # Base case: current string length is n*2 (full combination has been generated)
        if len(current) == n*2:
            answer.append(''.join(current))
            return

        # Path 1: Add to opens
        if openCount < n:
            current.append("(")
            self.backtrack(answer, current, openCount + 1, closeCount, n)
            current.pop()

        # Path 2: Add to closes
        if closeCount < openCount:
            current.append(")")
            self.backtrack(answer, current, openCount, closeCount + 1, n)
            current.pop()

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.backtrack(result, [], 0, 0, n)

        return result