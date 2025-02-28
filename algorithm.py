
# Made on Arch Linux, BTW.
# mc_modder, 2025

import math
import time

def algorithm(num):
    if num <= 1:
        return 'n'
    if num == 2:
        return 'y'
    if num % 2 == 0:
        return 'n'
    
    
    for i in range(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return 'n'
    return 'y'

def calc(starting_num, iterations):
    for i in range(1, iterations):
        print(f"{starting_num} {algorithm(starting_num)}")
        starting_num += 1

def main():
    
    x = int(input("starting number: "))
    y = int(input("iterations: "))
    
    
    start_time = time.perf_counter()
    
    
    calc(x, y)
    print("Done")
    
    
    duration = time.perf_counter() - start_time
    print(f"Calculation time: {duration:.8f} seconds")
    
    
    z = input("Write prime nums? (y/n): ")
    if z.lower() == 'y':
        with open('prime_numbers.txt', 'w') as f:
            for num in range(x, y + 1):
                if algorithm(num) == 'y':
                    f.write(str(num) + '\n')
        print("Done")
    elif z.lower() == 'n':
        print("Finished")
    else:
        print("Program Complete")

if __name__ == "__main__":
    main()
