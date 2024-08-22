import sys

def build_trie(strings):
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.is_end_of_word = False
    
    root = TrieNode()
    for s in strings:
        node = root
        for char in s:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
    return root

def calculate_height(node):
    if not node.children:
        return 1
    return 1 + max(calculate_height(child) for child in node.children.values())

def determine_winner(n, k, strings):
    trie_root = build_trie(strings)
    height = calculate_height(trie_root)
    
    # Determine who wins a single game based on height
    if height % 2 == 1:
        single_game_winner = "First"
    else:
        single_game_winner = "Second"
    
    # Determine who wins the k-th game
    if k % 2 == 1:
        return single_game_winner
    else:
        return "Second" if single_game_winner == "First" else "First"

# # Input reading
# input = sys.stdin.read().splitlines()
# n, k = map(int, input[0].split())
# strings = input[1:]
n, k = 2, 3
strings = [
    "a",
    "b"
]

# Determine the winner
print(determine_winner(n, k, strings))
