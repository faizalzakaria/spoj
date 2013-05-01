#!/usr/bin/env ruby

####################################
#   @author Faizal Zakaria
#    Test case generator
###################################

require 'digest/md5'

MAX_RANDOM = 100000000
MAX_VALUE = 20000
CONSTRAINT = 10000
$ERROR = 0
def test
  #value = rand(10000)
  value = MAX_VALUE
  toto1 = File.join( Dir.pwd, "T1" )
  toto2 = File.join( Dir.pwd, "T2" )
  input = File.join( Dir.pwd, "orderStatisticSetTC" )

  system("./orderStatisticSet.rb #{value} > /dev/null")

  unless !system("./orderStatisticSet < #{input} > #{toto1}")
    md51 = `md5sum #{toto1}`
    md51 = md51.split(' ')[0]
    #puts "#{md51}"

    unless !system("./orderStatisticSetBF < #{input} > #{toto2}")
      md52 = `md5sum #{toto2}`
      md52 = md52.split(' ')[0]
      #puts "#{md52}"

      if md51 == md52
        puts "CORRECT"
      else
        puts "XXXXXXX"
        $ERROR += 1
        puts "mv #{input} TestCaseIncorrect"
        system "mv #{input} TestCaseIncorrect"
      end
    end
  end
end

for i in 1..ARGV[0].to_i do
  test
end

puts "Total error : #{$ERROR}"
