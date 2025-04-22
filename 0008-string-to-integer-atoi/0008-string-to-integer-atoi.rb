# @param {String} s
# @return {Integer}
def my_atoi(s)
    [[-2147483648, s.to_i].max, 2147483647].min
end