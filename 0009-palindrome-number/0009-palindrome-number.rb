def is_palindrome(x)
  return false if x < 0

  original = x
  reversed = 0

  while x > 0
    digit = x % 10
    reversed = reversed * 10 + digit
    x /= 10
  end

  original == reversed
end

# Examples
puts is_palindrome(121)   # true
puts is_palindrome(-121)  # false
puts is_palindrome(10)    # false
