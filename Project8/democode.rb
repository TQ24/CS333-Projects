#!/usr/bin/ruby

def func1
  a = 0
  while a<2
    puts "func1 at: #{Time.now}"
    sleep(2)
    a = a+1
  end
end

def func2
  b = 0
  while b<=2
    puts "func2 at: #{Time.now}"
    sleep(1)
    b = b+1
  end
end

puts "Started at #{Time.now}"
t1 = Thread.new{func1()}
t2 = Thread.new{func2()}
t1.join
t2.join
puts "End at #{Time.now}"
