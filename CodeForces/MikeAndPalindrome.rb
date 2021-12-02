cad = gets.chomp
len = cad.size
ans = 0

(0 .. (len-1)/2).each do | i |
	ans += 1 unless cad[ i ] == cad[ len-i-1 ]
end

if( ans > 1 )
	puts "NO"
elsif ans == 1
	puts "YES"
elsif( len&1 )
	puts "YES"
else
	puts"NO"
end
