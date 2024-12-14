def longest_common_prefix(strs)
  return "" if strs.empty?

  prefix = strs[0]

  strs.each do |str|
    while str.index(prefix) != 0
      prefix = prefix[0...-1]
      return "" if prefix.empty?
    end
  end

  prefix
end

puts longest_common_prefix(["flower", "flow", "flight"])  # Output: "fl"
puts longest_common_prefix(["dog", "racecar", "car"])     # Output: ""
puts longest_common_prefix([])                            # Output: ""