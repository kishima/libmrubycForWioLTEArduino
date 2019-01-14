Wio.power_supply_LTE(true)
Wio.turnon_or_reset
Wio.activate("soracom.io", "sora", "sora")
sock = Wio.sock_open_udp("harvest.soracom.io",8514)

val = UltraSonic.read
Wio.sock_send(sock,"{\"distance\":#{val}}")
Wio.sock_close(sock)

puts "done"

