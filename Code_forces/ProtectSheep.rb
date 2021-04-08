def is_sheep( i, j, mat, row, col )
	return false if i < 0 || i >= row 
	return false if j < 0 || j >= col

	return mat[ i ][ j ] == "S" 
end

row,col = gets.chomp.strip.split(" ")
row = row.to_i
col = col.to_i

mat = []
x = [ 0, -1, 0, 1 ]
y = [ 1, 0, -1, 0 ]

(0..row-1).each do
	mat << gets.chomp
end

ban = true

(0..row-1).each do | i |
	(0..col-1).each do | j |
		if( mat[ i ][ j ] == "W" )
			(0..3).each do | k |
				ban = false if( is_sheep i+x[ k ], j+y[ k ], mat, row, col )
			end
		end
	end
end

if ban
	puts "Yes"
	mat.each do | cad |
		(0..col-1).each do | i |
			print cad[ i ] == "." ? "D" : cad[ i ]
		end
		print "\n"
	end
else
	puts "No"
end

