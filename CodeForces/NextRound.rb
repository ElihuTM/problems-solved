n,k = gets.chomp.strip.split(" ")
n = n.to_i
k = k.to_i

arr = gets.chomp.strip.split(" ")
cont = 0

arr.each do | c |
	c = c.to_i
	cont += 1 if c >= k && c > 0
end
puts cont
