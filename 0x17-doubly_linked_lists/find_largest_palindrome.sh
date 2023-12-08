#!/bin/bash

is_palindrome() {
    local str="$1"
    [[ "$str" == "$(echo "$str" | rev)" ]]
}

find_largest_palindrome() {
    local largest_palindrome=0

    for i in {100..999}; do
        for j in {100..999}; do
            product=$((i * j))
            if is_palindrome "$product" && ((product > largest_palindrome)); then
                largest_palindrome="$product"
            fi
        done
    done

    echo "$largest_palindrome"
}

result=$(find_largest_palindrome)

echo -n "$result" > 102-result
