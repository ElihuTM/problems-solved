def f( n )
	return 1 if n == 0
	return 2 if n == 1

	pot = 1
	while( (pot << 1) <= n )
		pot <<= 1
	end

	return 2 * f( n-pot )
end

n = gets.chomp.to_i
puts f( n )
