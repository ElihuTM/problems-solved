n = gets.chomp.strip.split(",").map { |str| str.to_i }

it = 0
while( n[ it ] != 99 )
	str = n[ it ].to_s
	op =  str.size >= 2 ? str[ str.size-2, 2 ].to_i : n[ it ]

	modo = [ 0, 0, 1 ]
	modo[ 0 ] = str[ -3 ].to_i if str.size >= 3
	modo[ 1 ] = str[ -4 ].to_i if str.size >= 4
	modo[ 2 ] = str[ -5 ].to_i if str.size >= 5

	resp = [ 0, 0 , 0 ]
	for j in 0..2 do
		if modo[ j ] == 1
			resp[ j ] = n[ it+j+1 ].to_i
		else
			resp[ j ] = n[ n[ it+j+1 ].to_i ].to_i
		end
	end

	if op == 3
		it == 0 ? n[ n[ it+1 ] ] = 5 : n[ resp[ 0 ] ] = 5
		it += 2
	elsif op == 4
		puts resp[ 0 ]
		it += 2
	elsif op == 2
		n[ resp[2] ] = resp[ 1 ] * resp[ 0 ]
		it += 4
	elsif op == 1
		n[ resp[2] ] = resp[ 1 ] + resp[ 0 ]
		it += 4
	elsif op == 5 
		if resp[ 0 ] != 0
			it = resp[ 1 ]
		else
			it += 3
		end
	elsif op == 6 
		if resp[ 0 ] == 0
			it = resp[ 1 ]
		else
			it += 3
		end
	elsif op == 7 
		if resp[ 0 ] < resp[ 1 ]
			n[ resp[ 2 ] ] = 1
		else
			n[ resp[ 2 ] ] = 0
		end
		it += 4
	else
		if resp[ 0 ] == resp[ 1 ]
			n[ resp[ 2 ] ] = 1
		else
			n[ resp[ 2 ] ] = 0
		end
		it += 4
	end
end