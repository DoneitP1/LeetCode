def roman_to_int(s)
  roman_values = {
    'I' => 1, 'V' => 5, 'X' => 10, 
    'L' => 50, 'C' => 100, 'D' => 500, 'M' => 1000
  }

  total = 0
  prev_value = 0

  s.chars.reverse.each do |char|
    current_value = roman_values[char]
    if current_value < prev_value
      total -= current_value
    else
      total += current_value
    end
    prev_value = current_value
  end
  
  total
end

# Example Usage
puts roman_to_int("III")      # Output: 3
puts roman_to_int("LVIII")    # Output: 58
puts roman_to_int("MCMXCIV")  # Output: 1994
