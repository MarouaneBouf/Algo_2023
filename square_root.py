def squareRoot(number, precision=5):
	start = 0
	end, ans = number, 1

	while (start <= end):
		mid = int((start + end) / 2)

		if mid**2 == number:
			ans = mid
			break
		if mid**2 < number:
			start = mid + 1
			ans = mid
		else:
			end = mid - 1
   
	increment = 0.1
	for _ in range(precision):
		while (ans * ans <= number):
			ans += increment
   
		ans = ans - increment
		increment = increment / 10

	return ans

print(squareRoot(2))

