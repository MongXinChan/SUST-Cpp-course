foo = ['dog', 'cat', 'bird']
for bar in foo:
    print(bar)

for index, value in enumerate(foo):
	print('%d: %4s' % (index, value))  
	print('{0}: {1}'.format(index, value))

for i in range(10):
        print(i,end=" ")