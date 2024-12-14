def has_groups_size_x(deck)
    deck.tally.values.reduce {|acc, val| acc.gcd(val)} > 1
end