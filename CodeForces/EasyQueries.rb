class SegmentTree
	attr_accessor :arbol, :cambios

	def initialize( n )
		@cambios = [ 0 ] * (6*n)
		@arbol = [ 0 ] * (6*n)
	end
	
	def propagar( p, i, j )
		arbol[ p ] += (j-i+1)*cambios[ p ]

		unless i == j
			cambios[ p<<1 ] += cambios[ p ]
			cambios[ (p<<1)+1 ] += cambios[ p ]
		end

		cambios[ p ] = 0
	end

	def query( p, i, j, a, b )
		return 0 if i > b || j < a
	
		propagar( p, i, j)
		return arbol[ p ] if i >= a && j <= b

		l = query( p<<1, i, (i+j)>>1, a, b )
		r = query( (p<<1)+1, ((i+j)>>1)+1, j, a, b)

		return l+r
	end

	def update( p, i, j, a, b, value )
		propagar( p, i, j )

		return if i > b || j < a

		if i >= a && j <= b
			arbol[ p ] += (j-i+1)*value

			unless( i == j )
				cambios[ p<<1 ] += value
				cambios[ (p<<1)+1 ] += value
			end
			return
		end

		update( p<<1, i, (i+j)>>1, a, b, value)
		update( (p<<1)+1, ((i+j)>>1)+1, j, a, b, value)

		arbol[ p ] = arbol[ p<<1 ] + arbol[ (p<<1)+1 ]
	end
end

n,x,q = gets.chomp.strip.split(" ")
n = n.to_i
x = x.to_i
q = q.to_i

segment = SegmentTree.new( n )
q.times do
	op = gets.chomp.strip.split(" ")
	_a = op[ 1 ].to_i
	_b = op[ 2 ].to_i

	if op[ 0 ] == "1"
		_c = op[ 3 ].to_i
		segment.update( 1, 0, n-1, _a-1, _b-1, _c )
	else
		puts segment.query( 1, 0, n-1, _a-1, _b-1 ) * x
	end
end
