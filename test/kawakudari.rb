cls; x=15
while true
  lc x,5; print "O"
  lc rnd(32),23; print "*"
  wait 3
  k=inkey()
  x=x-(k==28?1:0)+(k==29?1:0)
  if scr(x,5)!=32
    break
  end
end
