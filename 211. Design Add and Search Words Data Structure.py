class Node:
    # trie tree
    def __init__(self):
        self.edges = {}
        # end flag: 1 means end
        self.X = 0

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str):
        def dfs(node, i):
            if i == len(word):
                node.X = 1
                return

            if node.edges.get(word[i]) is None:
                node.edges[word[i]] = Node()
            dfs(node.edges[word[i]], i+1)

        dfs(self.root, 0)

    def addWord(self, word: str) -> None:
        self.insert(word)

    def search(self, word: str) -> bool:
        def dfs(node, i):
            if i == len(word):
                if node.X == 1:
                    return True
                return False
            if word[i] == '.':
                k = False
                for j in node.edges.keys():
                    k = k or dfs(node.edges[j], i+1)
                return k
            if node.edges.get(word[i]) is None:
                return False
            return dfs(node.edges[word[i]], i+1)
        return dfs(self.root, 0)
