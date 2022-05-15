def algo(x: float, r: float) -> float:
	k, xk, Crk, terme, res = 0, 1, 1, 1, 1

	while abs(terme) > (2 ** -30):
		xk *= x
		Crk *= (r-k) / (k+1)
		terme = Crk * xk
		res += terme
		k += 1
	
	return res

print(algo(1, 1/2))