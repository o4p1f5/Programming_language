# 2803.py
def read_data(file_name):
	data_list = []
	f = open(file_name, 'r')
	for line in f: # f.readlines()
		name, kor, eng, math = line.split()
		tmp = [ name, int(kor), int(eng), int(math)]
		data_list.append(tmp)
	f.close()
	return data_list
    
def calculateAvg(data_list):
	for item in data_list:
		name, kor, eng, math = item
		sumScore = kor + eng + math
		item.append(sumScore)
		item.append(sumScore/3.0)
		
def write_data(file_name, data_list):
	f = open(file_name, 'w')
	f.write('    name,     kor,     eng,    math,    sum,     avg\n')
	f.write('------------------------------------------------------\n')	
	for item in data_list:
		s = ""
		for data in item:
			if type(data) == float:
				s += "{0:8.2f}".format(data)
			else:
				s  += "{0:>8},".format(data)
		s += '\n'			
		f.write(s)
	f.close()

std_list = read_data('data.txt')
print(std_list)

calculateAvg(std_list)
print(std_list)

write_data('result.txt', std_list)
