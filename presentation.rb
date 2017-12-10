def add_eight(number)
  number + 8
end

returned_value = add_eight(24)
puts returned_value


#------------------------------------
def add_four(number)
  return number + 4
  number + 8
end

returned_value2 = add_four(24)
puts returned_value2


#------------------------------------
def add_three(number)
  puts number + 3
end

#add_three(5)   # This should return 8
#add_three(5).times { puts "This should print 8 times "}
return_test = add_three(5).times { puts "This should print 8 times "}
puts return_test

test = "hi there".length.to_s
puts test
# prints out 8
puts test.instance_of? String
# prints out true
