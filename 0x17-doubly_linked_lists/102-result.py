#!/usr/bin/python3
def is_palindrome(number):
    # Convert the number to a string and check if it reads the same both ways
    return str(number) == str(number)[::-1]

def largest_palindrome():
    max_palindrome = 0

    # Iterate through all possible products of two 3-digit numbers
    for i in range(100, 1000):
        for j in range(100, 1000):
            product = i * j
            if is_palindrome(product) and product > max_palindrome:
                max_palindrome = product

    return max_palindrome

result = largest_palindrome()

# Save the result to the file '102-result'
with open('102-result', 'w') as file:
    file.write(str(result))
