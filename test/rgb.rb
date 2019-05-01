led 1
while btn()==0
end
led 0

while true
  out 2,1; wait 10
  out 3,1; wait 10
  out 4,1; wait 10
  out 4,0; wait 10
  out 3,0; wait 10
  out 2,0; wait 10
end
