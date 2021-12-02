def bfs( root, list, dist)
	q = Queue.new
	dist[ root ] = 0
	q << root

	until q.empty?
		front = q.pop
		list[ front ].each do |v|
			if dist[ v ] == -1
				dist[ v ] = dist[ front ] + 1
				q << v
			end
		end 
	end
end

list = {}
dist = {}

(1..1376).each do 
	a,b = gets.chomp.strip.split(")")

	if list[ a ] == nil 
		dist[ a ] = -1
		list[ a ] = [ ]
	end

	if list[ b ] == nil 
		dist[ b ] = -1
		list[ b ] = [ ]
	end
	
	list[ a ] << b
	list[ b ] << a
end

bfs( "YOU", list, dist )
puts dist["SAN"]