    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        def dfs(key, word, v):
            if v.get(key) is not None:
                return
            v[key] = 1
            word[key] = 1
            for i in graph[key]:
                dfs(i, word, v)
        
        def replace(string):
            if v.get(string) is not None:
                return
            v[string] = 1
            ans.append(string[:-1])
            j = 0
            string += " "
            for i in range(len(string)):
                if string[i] == ' ':
                    s = string[j:i]
                    if words.get(s) is not None:
                        if len(words[s]) > 0:
                            for key in words[s].keys():
                                if key != s:
                                    replace(string[:j] + key + string[i:-1])
                    j = i+1
        graph = {}
        # make graph
        for pair in synonyms:
            if graph.get(pair[0]) is None:
                graph[pair[0]] = []
            if graph.get(pair[1]) is None:
                graph[pair[1]] = []
            graph[pair[0]].append(pair[1])
            graph[pair[1]].append(pair[0])
        
        words = {}
        ans = []
        j = 0
        text += " "
        for i in range(len(text)):
            if text[i] == " ":
                s = text[j:i]
                if words.get(s) is None and graph.get(s) is not None:
                    words[s] = {}
                    dfs(s, words[s], {})
                j = i+1
        
        v = {}
        replace(text)
        ans.sort()
        return ans
