class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.end_of_word = False

    def insert(self, word: str) -> None:
        current = self
        for char in word:
            index = ord(char) - ord("a")
            if current.children[index] == None:
                current.children[index] = Trie()
            current = current.children[index]
        current.end_of_word = True

    def search(self, word: str) -> bool:
        current = self
        for char in word:
            index = ord(char) - ord("a")
            if current.children[index] == None:
                return False
            current = current.children[index]
        return current.end_of_word

    def startsWith(self, prefix: str) -> bool:
        current = self
        for char in prefix:
            index = ord(char) - ord("a")
            if current.children[index] == None:
                return False
            current = current.children[index]
        return True
