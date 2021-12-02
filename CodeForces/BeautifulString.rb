def fun ( cad )
	for i in 0..cad.size-1 do
		if cad[ i ] == '?'
			pos = { 'a' => 0, 'b' => 0, 'c' => 0 }

			pos[ cad[ i-1 ] ] = 1 if i > 0
			pos[ cad[ i+1 ] ] = 1 if i < cad.size-1

			pos.each do | key, value |
				if value == 0
					cad[ i ] = key
					break
				end
			end
		else
			return -1 if ( i > 0 && cad[ i-1 ] == cad[ i ] )
			return -1 if ( i < cad.size-1 && cad[ i ] == cad[ i+1 ] )
		end
	end

	return cad
end

t = gets.chomp.to_i
until t == 0
	cad = gets.chomp
	puts fun( cad )
	t -=1
end