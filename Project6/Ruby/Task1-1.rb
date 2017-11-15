# CS333
# Project 6
#
# Extensions: Choose a third selected language
# Creating a file and write to it

fname = "output.txt"
somefile = File.open(fname,"w")
somefile.puts "Hello World!"
somefile.close

file = File.open("output.txt","r")
contents = file.read
puts "Contents of output.txt: "
puts contents
