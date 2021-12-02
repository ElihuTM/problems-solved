def is_prime( n )

	return false if n % 2 == 0 && n != 2

	div = 3
	while( div * div <= n )
		return false if n % div == 0
		div += 2
	end

	return true;
end

n = gets.chomp.to_i

if is_prime( n )
	puts 1
elsif n % 2 == 0 || is_prime( n-2 )
	puts 2
else
	puts 3
end
