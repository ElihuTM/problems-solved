n = gets.chomp.to_i

max = gets.chomp.to_i
aux = max
for i in (1..n-1)
	x = gets.chomp.to_i
	aux = x if x > aux
end

if max == aux
	puts "S"
else
	puts "N"
end
