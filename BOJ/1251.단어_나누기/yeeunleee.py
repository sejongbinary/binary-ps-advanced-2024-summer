word = input()
word_list = []

for i in range(1, len(word) - 1):
    for j in range(i + 1, len(word)):
        first = word[:i]
        second = word[i:j]
        third = word[j:]

        new_word = first[::-1] + second[::-1] + third[::-1]
        word_list.append(new_word)
    
print(min(word_list))