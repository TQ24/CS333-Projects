# CS333
# Project 6
#
# Extensions: Choose a third selected language
# FUNCTIONS
# Pass unknow number of arguments

def foo(a, b, c, *others)
  puts a
  puts b
  puts c
  puts others.join(',')
end

def foo2(a,b,c, *others)
  sum = 0
  sum = sum + a
  sum = sum + b
  sum = sum + c
  i = 0;
  while i < others.length
    sum = sum + others[i]
    i = i+1
  end
  puts sum
end

puts "---Output of foo():---"
foo(1,1,2,3,5,8,13)
puts "---Output of foo2():---"
foo2(1,1,2,3,5,8,13)
