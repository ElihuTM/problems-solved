def is_increase( str )
	for i in ( 1..str.size-1 ) do
		return false if str[ i ] < str[ i-1 ]
	end

	return true
end

def have_two( str )
	ban = false
	i = 0

	while( i < str.size )
		c = str[ i ]
		cont = 0
		while i < str.size && str[ i ] == str[ c ]
			cont += 1
			i += 1
		end
		ban = true if cont == 2
	end

	return ban
end

puts have_two( "111122")

ans = 0
for i in 278384..824795 do
	c = i.to_s
	if is_increase( c ) && have_two( c )
		ans += 1
	end
end
puts ans