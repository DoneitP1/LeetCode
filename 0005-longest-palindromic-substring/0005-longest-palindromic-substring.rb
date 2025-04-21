# @param {String} s
# @return {String}
def longest_palindrome(s)
    def expand_around_center(s, left, right)
        while left >= 0 && right < s.length && s[left] == s[right]
            left -= 1
            right += 1
        end
        s[left + 1...right]
    end

    longest = ""

    (0...s.length).each do |i|
        odd = expand_around_center(s, i, i)
        even = expand_around_center(s, i, i + 1)

        if odd.length > longest.length
            longest = odd
        end

        if even.length > longest.length
            longest = even
        end
    end

    return longest
end

# Example usage
s = "babad"
result = longest_palindrome(s)
puts "Longest Palindromic Substring: #{result}"