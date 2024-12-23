require 'prime'
@pals = [*"0".."9"]
4.times do # 1, 3, 5, 7, 9 digits
  nxt = @pals.dup
  (0..9).each do |digit|
    @pals.each do |pal|
      nxt << digit.to_s + pal + digit.to_s
    end
  end
  @pals = nxt
end
@pals.insert(10, "11")
@pals = @pals.map(&:to_i).select(&:prime?)
def prime_palindrome(n)
  n = 1e8 if 1e7 < n && n < 1e8
  @pals.find do |pal|
    pal >= n
  end
end