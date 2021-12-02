b,p,f = gets.chomp.strip.aplit(" ")
c,p = gets.chomp.strip.split(" ")

ans = 0
if c > p
	if 2*b > p
		ans += c * p
		b -= 2*p

		ans += (2*b > f ? p*f : (b/2)*f )
	else
		ans += ()
else

end
