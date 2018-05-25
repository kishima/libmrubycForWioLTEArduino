r=0
g=0
b=0
while true
	r=b/2
	g=b/3
	puts "mruby/c example: control LED B="+b.to_s
	Wio.control_led(r,g,b)
	sleep(1)
	b=b+10
	b=0 if b>60
end

