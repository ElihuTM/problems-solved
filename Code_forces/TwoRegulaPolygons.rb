t = gets.chomp.to_i

while t > 0
	n,m = gets.chomp.strip.split(" ").each{ |x| x = x.to_i }

	puts n+m
	t -= 1
end