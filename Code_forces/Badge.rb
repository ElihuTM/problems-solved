n = gets.chomp.to_i
arr = gets.chomp.strip().split(" ")

(0..n-1).each do | i |
	visit = [ 0 ] * n
	
	nodo = i
	while visit[ nodo ] == 0
		visit[ nodo ] = 1
		nodo = arr[ nodo ].to_i - 1
	end
	print nodo+1

	print " " unless i == n-1
end
print "\n"
