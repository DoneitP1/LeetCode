def is_valid(s)
    brackets = []
    
    s.chars.each do |c|
        if c == '(' || c == '{' || c == '['
            brackets.push(c)
        else
            if brackets.empty?
                return false  # There's no matching open bracket.
            end
            
            open_bracket = brackets.pop
            
            if (c == ')' && open_bracket != '(') || (c == '}' && open_bracket != '{') || (c == ']' && open_bracket != '[')
                return false  # Mismatched closing bracket.
            end
        end
    end
    
    brackets.empty?
    end