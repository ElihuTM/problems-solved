class Circ
	x = 0
	y = 0
	r = 0
	def initialize(a,b,c)
		x = a
		y = b
		r = c
	end
end

$point = new Circ[]

n,m,k = gets.chomp.strip.split(" ")
n = n.to_i
m = m.to_i
k = k.to_i

for i in (0..k-1)
	x,y,r = gets.chomp.strip.split(" ")
	$point << Circ.new(x.to_i, y.to_i, r.to_i )
end

point.each do |c|
	puts "#{c.x} #{c.y} #{c.r}"
end
