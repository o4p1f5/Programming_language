# 2601.py
class Vec2:
	def __init__(self, x = 0, y = 0):
		self.x = x
		self.y = y
	def __add__(self, other):        # + 연산자 오버로딩
		x = self.x + other.x
		y = self.y + other.y
		return Vec2(x, y)

v1 = Vec2(1, 2)
v2 = Vec2(3, 4)
v3 = v1 + v2
print("v3: %s, %s" % (v3.x, v3.y))
