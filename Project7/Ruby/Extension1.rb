# CS333
# Project 7
# EXTENSIONS
# Ruby

GC.start
before = GC.stat(:total_freed_objects)

RETAINED = []
100_000.times do
  RETAINED << "a string"
end

GC.start
after = GC.stat(:total_freed_objects)
puts "-------------Global---------------"
puts "Objects Freed: #{after - before}"
#source:https://www.sitepoint.com/ruby-uses-memory/
puts "-------------Local---------------"

GC.start
before2 = GC.stat(:total_freed_objects)

100_000.times do
  foo = "a string"
end

GC.start
after2 = GC.stat(:total_freed_objects)
puts "Objects Freed: #{after2 - before2}"
