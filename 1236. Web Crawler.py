# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        slash = 0
        for i, c in enumerate(startUrl):
            if c == '/':
                slash+=1
                if slash == 3:
                    hostname = startUrl[:i]
                    break
        else:
            hostname = startUrl
        v = {}
        out = []
        def dfs(url, hostname):
            v[url] = 1
            out.append(url)
            for i in htmlParser.getUrls(url):
                if hostname in i and v.get(i) is None:
                    dfs(i, hostname)
                    
        dfs(startUrl, hostname)
        return out
