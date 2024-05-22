import random
import os
from math import gcd
from tqdm import tqdm
import numpy as np

compile_initial = True
T = 10000  # Number of test inputs
multiple_test_cases = False
tc = 1 # Number of test cases per test input

def generate_test_case():
    n = 5  # Number of elements in the array
    a = [random.randint(0, 7) for _ in range(n)]
    res = f'{n}\n'
    res += ' '.join(map(str, a)) + '\n'
        
    return res

def test():
    res = ""
    if multiple_test_cases:
        res += f"{tc}\n"

    for _ in range(tc):
        res += generate_test_case()

    # Write the test case to the input file
    with open("input.txt", "w") as f:
        f.write(res)

    # Run the solutions
    os.system("./sol < input.txt > output_sol.txt")
    os.system("./brute < input.txt > output_brute.txt")

    # Compare the outputs
    with open("output_sol.txt", "r") as f:
        output_sol = f.read()

    with open("output_brute.txt", "r") as f:
        output_brute = f.read()

    for line_sol, line_brute in zip(output_sol.split("\n"),
                                    output_brute.split("\n")):
        if line_sol.strip() != line_brute.strip():
            print("Wrong answer")
            print("Input:", res)
            print("Output:", line_sol)
            print("Expected:", line_brute)
            exit(0)


# Generate test cases
if __name__ == "__main__":
    if compile_initial:
        print("Compiling the solutions")
        os.system("g++ -std=c++20 brute.cpp -o brute")
        os.system("g++ -std=c++20 sol.cpp -o sol")
        print("Compilation done")
    for i in tqdm(range(T)):
        test()
        

# def get_array(size, min_value, max_value):
#     arr = [random.randint(min_value, max_value) for _ in range(size)]
#     return arr


# def array_to_string(array):
#     return ' '.join([str(x) for x in array])

# def get_lowercase_string(size):
#     return ''.join([chr(random.randint(97, 122)) for _ in range(size)])


# def get_l_r(n):
#     _l = random.randint(1, n)
#     _r = random.randint(_l, n)
#     return _l, _r


# def generate_cases(num_tests, min_array_size, max_array_size, min_value,
#                    max_value):
#     arrays = [
#         get_array(
#             size=random.randint(min_array_size, max_array_size),
#             min_value=min_value, max_value=max_value
#         )
#         for _ in range(num_tests)
#     ]
#     return f"{num_tests}\n" + "\n".join([
#         f"{len(array)}  {array_to_string(array)}"
#         for array in arrays
#     ])


# def get_graph(n, sparsity=0.2):
#     mat = np.random.randint(0, int(1 / sparsity), (n, n))
#     edges = list()
#     for i in range(n):
#         for j in range(i + 1, n):
#             if mat[i][j] == 1:
#                 edges.append((i + 1, j + 1))
#     return edges


# def get_tree(n):
#     edges = list()
#     if n > 1:
#         edges.append((1, 2))
#     if n > 2:
#         edges.append((1, 3))
#     for i in range(4, n + 1):
#         edges.append((random.randint(1, i - 1), i))
#     return edges