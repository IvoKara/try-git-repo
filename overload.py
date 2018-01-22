def strange_for(twotuple):
	print(type(twotuple))
	for first_arg, second_arg in twotuple:
		print(first_arg, second_arg)
		
if __name__ == "__main__":
	t = (1, 3), (3.4, 54.3), (True, False), (None, 0), ("Hello", "LOL")
	strange_for(t)
