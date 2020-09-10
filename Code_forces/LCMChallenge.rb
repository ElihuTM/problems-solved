def gcd( a, b )
	return b == 0 ? a : gcd( b, a%b );
end

def calc( a, b, c )
	aux = a * ( b / gcd( a,b) )
	return aux * ( c / gcd( aux, c ) )
end

def max( a, b )
	return a > b ? a : b
end

n = gets.chomp.to_i
ans = [1,2,6]

if n < 4
	puts ans[ n-1 ]
else
	ans = calc( n, n-1, n-2 )
	for i in ( max( n-50,1 )..n )
		for j in ( max( n-50,1 )..n )
			for k in ( max( n-50,1 )..n )
				ans = max( ans, calc( i, j, k ) )
			end		
		end	
	end

	puts ans
end