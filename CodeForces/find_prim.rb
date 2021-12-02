def is_pal( c )
	for i in (2..c-1)
		break if i*i > c

		return false if c % i == 0

	end
	return true
end

(1000000000..1000000100).each do | c |
	if is_pal( c )
		puts c
	end
end