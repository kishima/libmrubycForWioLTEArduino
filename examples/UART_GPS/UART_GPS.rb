Wio.power_supply_grove(true)
sleep(1)
Serial.begin(9600)
sleep(1)

while true
  line = Serial.readline
  puts line if line != false && line != nil
  Arduino.delay(10) if line == false || line == nil
end
