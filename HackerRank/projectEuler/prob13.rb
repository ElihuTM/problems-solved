n = gets.chomp.to_i
ans = 0

while( n != 0 )
	x = gets.chomp.to_i
	ans += x
	n -= 1
end

while( ans >= 10000000000 )
	ans /= 10
end

puts ans

