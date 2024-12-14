def find_median_sorted_arrays(nums1, nums2)
  if nums1.length > nums2.length
    return find_median_sorted_arrays(nums2, nums1)
  end

  x = nums1.length
  y = nums2.length
  low = 0
  high = x

  while low <= high
    partition_x = (low + high) / 2
    partition_y = (x + y + 1) / 2 - partition_x

    max_left_x = (partition_x == 0) ? -Float::INFINITY : nums1[partition_x - 1]
    min_right_x = (partition_x == x) ? Float::INFINITY : nums1[partition_x]

    max_left_y = (partition_y == 0) ? -Float::INFINITY : nums2[partition_y - 1]
    min_right_y = (partition_y == y) ? Float::INFINITY : nums2[partition_y]

    if max_left_x <= min_right_y && max_left_y <= min_right_x
         if (x + y).even?
        return ([max_left_x, max_left_y].max + [min_right_x, min_right_y].min) / 2.0
      else
        return [max_left_x, max_left_y].max
      end
    elsif max_left_x > min_right_y
      # Move partition_x to the left
      high = partition_x - 1
    else
      low = partition_x + 1
    end
  end

  raise "Input arrays are not valid"
end
