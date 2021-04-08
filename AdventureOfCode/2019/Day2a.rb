q = gets.chomp.strip.split(",")
n = []

for l in 0..99 do
	for m in 0 .. 99 do

		for i in 0..q.size-1 do
			n[ i ] = q[ i ].to_i
		end

		n[ 1 ] = l
		n[ 2 ] = m
		i = 0
		while( n[ i ].to_i != 99)
			if( n[ i ].to_i == 1 )
				n[ n[ i+3 ].to_i ] = n[ n[ i+1 ].to_i ].to_i + n[ n[ i+2 ].to_i ].to_i
			else
				n[ n[ i+3 ].to_i ] = n[ n[ i+1 ].to_i ].to_i * n[ n[ i+2 ].to_i ].to_i
			end

			i += 4
		end

		if  n[ 0 ] == 19690720
			puts 100*l+m
		end
	end
end
puts n

/610685/