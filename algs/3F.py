class TrieNode:
    def __init__(self):
        self.children = {}
        self.end_of = False


def add_to_trie(root, word):
    node = root
    for char in word:
        if char not in node.children:
            node.children[char] = TrieNode()
        node = node.children[char]
    node.end_of = True


def find_shortest_matching_prefix(root, word):
    node = root
    prefix = ""
    for char in word:
        if char not in node.children:
            break
        node = node.children[char]
        prefix += char
        if node.end_of:
            return prefix
    return word


def shorten_text_based_on_dictionary(dictionary, text):
    root = TrieNode()
    for word in dictionary:
        add_to_trie(root, word)

    shortened_text = []
    for word in text:
        prefix = find_shortest_matching_prefix(root, word)
        shortened_text.append(prefix)

    return " ".join(shortened_text)


dictionary = input().split()
text = input().split()

shortened_text = shorten_text_based_on_dictionary(dictionary, text)
print(shortened_text)
