# 2701.py
class Person:
	def __init__(self, name, age, job=None):
		self.name = name
		self.age  = age
		self.job  = job
	def __str__(self):
		if self.job is 'Employee':
			return "{}({}, {}, {}, {})".format(self.job,
			self.name, self.age, self.company, self.salary)
		elif self.job is 'Student':
			return "{}({}, {}, {})".format(self.job,
			self.name, self.age, self.school)
		else:
			return "Person(name={}, age={})".format(self.name,
								self.age)	

class Employee(Person):
	def __init__(self, name, age, company, salary=100):
		super().__init__(name, age, 'Employee')
		self.company = company
		self.salary  = salary
		
class Student(Person):
	def __init__(self, name, age, school):
		super().__init__(name, age, 'Student')
		self.school = school

p1 = Person('Kim', 20)
print(p1)

p2 = Employee('Lee', 25, 'Google', 1000)
print(p2)

p3 = Student('Park', 20, 'Hankook Univ.')
print(p3)
