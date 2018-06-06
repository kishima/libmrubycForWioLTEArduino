sleep(1)
Wio.power_supply_grove(true)
sleep(2)
Serial.begin(9600)
sleep(3)

while true
  line = Serial.readline
  puts line if line != false
  Arduino.delay(10) if line == false
end
