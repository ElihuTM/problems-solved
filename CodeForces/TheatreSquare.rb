n,m,a = gets.chomp.strip.split(" ")

x = (n.to_f/a.to_f).ceil
y = (m.to_f/a.to_f).ceil

puts x*y
