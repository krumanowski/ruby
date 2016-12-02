def quicksort(array, from=0, to=nil)

    is_number = array.all? {|i| i.is_a?(Numeric) }

    if is_number != true
      abort("Błędny typ danych w tablicy. Wszystkie muszą być int lub float!")
    end

    if to == nil
        to = array.count - 1
    end

    if from >= to
        return
    end

    pivot = array[from]
    min = from
    max = to

    free = min

    while min < max
        if free == min
            if array[max] <= pivot
                array[free] = array[max]
                min += 1
                free = max
            else
                max -= 1
            end
        elsif free == max
            if array[min] >= pivot
                array[free] = array[min]
                max -= 1
                free = min
            else
                min += 1
            end
        else
            raise "Coś poszło mocno nie tak!"
        end
    end

    array[free] = pivot

    quicksort array, from, free - 1
    quicksort array, free + 1, to
end



#a = [1, 2, 3, 3.4, 4, 5, 6, 7, 8, 9, 9.1, 10, 11, 11.8, 12, 13, 14, 15].shuffle
#puts "Tablica:"
#print a
#puts
#quicksort a
#puts "Quicksort:"
#print a
