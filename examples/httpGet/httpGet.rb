sleep(1)

Wio.init
Wio.power_supply_LTE(true)
Wio.turnon_or_reset

Wio.activate("soracom.io", "sora", "sora")

url = "http://silentworlds.info"

response = Wio.http_get(url)
puts response

while true
	sleep(1)
end

