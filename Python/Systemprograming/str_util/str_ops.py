def find_all(text, keyword):
	result = []
	index = 0
	while (index >= 0):
		f = text.find(keyword, index)
		if f >= 0:
			result.append(f)
			index = f + 1
		else:
			break
	return result

# def count_all(text, keyword, insensitive=False):
# 	# sr.count_all(text="Hello HELLO", keyword="Hello", insensitive=True)
# 	count1 = 0
# 	count2 = 0
# 	count = 0
# 	if insensitive == True:
# 		keyword1 = keyword.lower()
# 		keyword2 = keyword.upper()
# 		print(keyword1, keyword2)
# 		count1 = text.count(keyword1)
# 		count2 = text.count(keyword2)
# 		count = count1 + count2
# 	else:
# 		count = text.count(keyword)
#
# 	return count