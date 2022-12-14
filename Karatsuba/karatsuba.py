def Karatsuba(x, y):
	if x < 10 or y < 10:
		return x * y
	num1_len = len(str(x))
	num2_len = len(str(y))
	n = max(num1_len,num2_len)
	nb = n//2
	a = x // (10 ** nb)
	b = x % (10 ** nb)
	c = y // (10 ** nb)
	d = y % (10 ** nb)
	print(a,b,c,d)
	ac = Karatsuba(a, c)
	bd = Karatsuba(b, d)
	ad_plus_bc = Karatsuba(a + b, c + d) - ac - bd
	return (10 ** (2*nb))*ac + (10 ** nb)*ad_plus_bc + bd


print(Karatsuba(15432,23))