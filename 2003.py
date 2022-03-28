# 2003.py
def isLeapYear(year):
	return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

print(isLeapYear(2012))
print(isLeapYear(2015))
