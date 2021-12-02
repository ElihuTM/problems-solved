n = gets.chomp.to_i
ans = 0;
while( n > 0 )
	a,b,c = gets.chomp.strip.split(" ")
	a = a.to_i
	b = b.to_i
	c = c.to_i

	ans += 1 if a+b+c > 1
	n -= 1
end

puts ans
