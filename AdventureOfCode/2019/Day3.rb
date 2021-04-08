def dist( x, y )
	x = x < 0 ? -x : x
	y = y < 0 ? -y : y
	return x+y
end

n = gets.chomp.strip.split(",")
m = gets.chomp.strip.split(",")

dir = [ [0,1], [-1,0], [0,-1], [1,0] ]
muv = { "R" => 0, "U"=> 1, "L" => 2, "D" => 3 }

map = {}

it = 1
x = 0
y = 0

n.each do |str|
	c = str[ 0 ]
	con = str[1,str.size-1].to_i

	for i in (1..con) do
		x += dir[ muv[c] ][ 0 ]
		y += dir[ muv[c] ][ 1 ]
		it += 1
		map[ [ x, y ] ] = it
	end
end

it = 0
x = 0
y = 0

ans = 99999999999999

m.each do |str|
	c = str[ 0 ]
	con = str[1,str.size-1].to_i
	for i in (1..con) do
		x += dir[ muv[c] ][ 0 ]
		y += dir[ muv[c] ][ 1 ]
		it += 1
		if ( map[ [ x, y ] ] != nil )
			ans = map[ [x,y] ]+it < ans ? map[ [x,y] ]+it : ans 
		end
	end
end

puts ans