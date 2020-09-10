while true
	n = gets.chomp.to_i
	break if n == 42

	m = ((n % 10) * 10) + (n / 10)
	puts (n > m ? m : n)
end
