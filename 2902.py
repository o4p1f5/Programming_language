# 2902.py
f1= open('C:/Users/Public/Pictures/Sample Pictures/Lighthouse.jpg', 'rb')
f2= open('Lighthouse.jpg', 'wb')
f2.write(f1.read())
f1.close()
f2.close()

f1 = open('C:/Users/Public/Videos/Sample Videos/Wildlife.wmv', 'rb')
f2 = open('Wildlife.wmv', 'wb')
f2.write(f1.read())
f1.close()
f2.close()
