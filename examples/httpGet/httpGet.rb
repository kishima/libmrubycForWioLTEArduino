Wio.Init
Wio.power_supply_LTE(true)
Wio.turnon_or_reset

Wio.activate(apn:"test", username:"test", password:"test")

response = Wio.http_get(url)
puts response

while true
	sleep(1)
end
