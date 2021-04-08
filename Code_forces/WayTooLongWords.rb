n = gets.chomp.to_i
while( n > 0 )
	cad = gets.chomp
	
	if cad.size <= 10
		puts cad 
	else
		puts "#{cad[ 0 ]}#{cad.size-2}#{cad[ cad.size-1 ]}"
	end
	n -= 1
end
