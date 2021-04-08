n = gets.chomp.to_i
arr = gets.chomp.split(" ").map{ |str| str.to_i }

arr2 = []
ans = []*n

it = 0
arr.each do | c |
	arr2 << [ c,it ]
	it += 1
end

arr2.sort!
arr.sort! { |x,y| y <=> x }

it = 0
arr.each do | c |
	ans[ arr2[ it ][ 1 ] ] = c
	it += 1
end

it = 0
ans.each do |x|
	print " " if it > 0
	print x

	it += 1
end

puts ""