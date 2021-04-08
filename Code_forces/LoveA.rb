cad = gets.chomp
as = 0

(0..cad.size-1).each do | i | 
	as += 1 if cad[ i ]  == 'a'
end

puts ( as > cad.size/2 ? cad.size : 2*as-1)
