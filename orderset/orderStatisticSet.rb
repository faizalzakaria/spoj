#!/usr/bin/env ruby

####################################
#   @author Faizal Zakaria
#    Test case generator
###################################

MAX_RANDOM = 2000000000

MAX_RANDOM_PARAM1 = 1000000001

if ARGV[0] != ""
  MAX_VALUE = ARGV[0].to_i
else
  MAX_VALUE = 5
end

toto = File.join( Dir.pwd, "orderStatisticSetTC" )
puts "#{toto}"

File.open( toto, 'w' ) { |out|
  out.puts "#{MAX_VALUE}"

  for i in 1..MAX_VALUE do

    op = rand(MAX_RANDOM)
    op %= 4
    param1 = rand(MAX_RANDOM)
    param1 %= MAX_VALUE + 1

    if (op == 0)
      out.puts "I #{param1}"
    elsif (op == 1)
      out.puts "D #{param1}"
    elsif (op == 2)
      out.puts "C #{param1}"
    else
      if param1 == 0
        param1 += 1
      end
      out.puts "K #{param1}"
    end
  end
}
