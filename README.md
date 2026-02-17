*This project has been created as part of the 42 curriculum by iarrien- and shierro*

# Push_Swap


# Description

The **Push Swap** project's goal is to create a program that sorts a random amount of integer numbers in increasing order using only two stacks and a limited set of operations.

The numbers are received as parameters of the program and initially stored in **stack A**, which is also the stack where they must end up once sorted.

The program must implement **four algorithms** with different levels of complexity, while also respecting a limit on the number of operations (performance constraint):

- A **simple algorithm** — `O(n²)`
- A **medium algorithm** — `O(n√n)`
- A **complex algorithm** — `O(n log n)`
- An **adaptive algorithm**, which selects different strategies depending on the initial level of disorder.

The user must be able to select the algorithm complexity using the following flags:

- `--simple`
- `--medium`
- `--complex`
- `--adaptive`

---

## Output

The Push Swap program will print the list of operations that takes place during the process of ordering the stack A.

---
## Available Operations

### Swap Operations

- **sa (swap a)**  
  Swap the first two elements at the top of stack A.  
  Does nothing if there is only one or no elements.

- **sb (swap b)**  
  Swap the first two elements at the top of stack B.  
  Does nothing if there is only one or no elements.

- **ss**  
  Perform `sa` and `sb` at the same time.

---

### Push Operations

- **pa (push a)**  
  Take the first element at the top of stack B and put it at the top of stack A.  
  Does nothing if stack B is empty.

- **pb (push b)**  
  Take the first element at the top of stack A and put it at the top of stack B.  
  Does nothing if stack A is empty.

---

### Rotate Operations

- **ra (rotate a)**  
  Shift up all elements of stack A by one.  
  The first element becomes the last one.

- **rb (rotate b)**  
  Shift up all elements of stack B by one.  
  The first element becomes the last one.

- **rr**  
  Perform `ra` and `rb` at the same time.

---

### Reverse Rotate Operations

- **rra (reverse rotate a)**  
  Shift down all elements of stack A by one.  
  The last element becomes the first one.

- **rrb (reverse rotate b)**  
  Shift down all elements of stack B by one.  
  The last element becomes the first one.

- **rrr**  
  Perform `rra` and `rrb` at the same time.

---

# Our Approach

## Simple Algorithm — `O(n²)`  
### Selection Sort Approach

This algorithm orders stack B in descending order and then pushes every number back to A.

It looks for the minimum number stacked in A and then pushes it to B, creating a descending order in B.

---

## Medium Algorithm — `O(n√n)`  
### Range-Based Sort Approach

This algorithm divides the *n* elements of stack A into √n chunks.

It navigates A, pushing elements of the current chunk to B until no chunks or elements remain.  
Elements in the upper part of each chunk are pushed toward the upper part of B, while elements in the lower part are pushed and then rotated toward the lower part of B.

This ensures that the largest element in B is never farther than √n positions from the top.

---

## Complex Algorithm — `O(n log n)`  
### Turk Approach

This algorithm orders stack B in descending order and then pushes every number back to A.

It starts by pushing the first two numbers from A to B. Then, for each remaining number in A, it calculates which element would require the fewest movements to be placed in the correct position in B and moves it accordingly. Although it is theoretically more demanding, in terms of push_swap movements makes the less movements possible.

---

## Adaptive Algorithm

The adaptive algorithm selects the strategy according to the disorder level:

- **Low disorder**: `disorder < 0.2`  
  → Use **O(n²)** algorithm.

- **Medium disorder**: `0.2 ≤ disorder < 0.5`  
  → Use **O(n√n)** algorithm.

- **High disorder**: `disorder ≥ 0.5`  
  → Use **O(n log n)** algorithm.

---
  ### Extra - Radix Sort Approach

Even though it is not featured in this version of Push Swap, we implemented the Radix Sort succesfully. However, it has not been as good in performance as the turk, so it has been sadly retired from the project.

This algorithm sorts elements based on their least significant bit at each iteration.

It iterates through stack A, pushing elements to B according to the current bit being evaluated, then moves them back to A before proceeding to the next bit.

Both this algorithm and the medium one operate on indexed values instead of raw input values.  
For example, with 500 numbers, values are normalized to indexes ranging from `0` to `499`, ensuring consistent operation counts for radix sort.


### Rationale

Less complex algorithms perform well when disorder is low because fewer movements are required overall. Using higher-complexity algorithms in those cases would unnecessarily increase CPU usage.

Therefore:

- Low disorder → Simple algorithm  
- Medium disorder → Medium algorithm  
- High disorder → Complex algorithm  

Thresholds are not evenly spaced because the number of operations in the simple algorithm increases significantly as disorder grows.

---

# Performance Benchmark

To validate the project, the following performance targets must be met:

## For 100 random numbers

- **< 2000 operations** → Minimum requirement  
- **< 1500 operations** → Good performance  
- **< 700 operations** → Excellent performance  

## For 500 random numbers

- **< 12000 operations** → Minimum requirement  
- **< 8000 operations** → Good performance  
- **< 5500 operations** → Excellent performance  

---

## Optional Benchmark Mode

When the `--bench` flag is used, the program must display (after sorting):

- The computed disorder percentage (with two decimals).
- The name of the selected strategy and its theoretical complexity class.
- The total number of operations.
- The count of each operation:
  - `sa`, `sb`, `ss`
  - `pa`, `pb`
  - `ra`, `rb`, `rr`
  - `rra`, `rrb`, `rrr`

The benchmark output must:

- Be sent to `stderr`.
- Only appear when the `--bench` flag is present.

# Bonus

The bonus part of this project consists of implementing the **checker** program, which is used to validate the output of `push_swap`.

The checker:

- Reads all the operations produced by `push_swap`.
- Applies them to the same input arguments.
- Verifies the final state of the stacks.

At the end of execution, it must output:

- `OK` → If stack A is sorted in ascending order and stack B is empty.
- `KO` → If stack A is not sorted or stack B is not empty.
- `Error` → If an invalid instruction or any other error is encountered.

The behavior must match the provided `checker_linux` from the project.

---



# Instructions

## Compilation

To compile the main program:

```bash
make
```


To compile the bonus (checker):

```bash
make bonus
```

## Usage

You can select the algorithm strategy using one of the following flags:

- `--simple`
- `--medium`
- `--complex`
- `--adaptive`

If multiple strategy flags are provided, **only the last one will be taken into account**.

You may also use:

- `--bench` → Activates benchmark mode.

### Example

```bash
./push_swap --complex 4 67 3 87 23
```

### Using the Checker (Bonus)

To validate the output using the checker, pipe the result of push_swap into checker, passing the same arguments:

```bash
ARG="4 67 3 87 23" ./push_swap --complex $ARG | ./checker $ARG
```

The checker will output:

- `OK` → If stack A is sorted and stack B is empty.

- `KO` → If stack A is not sorted or stack B is not empty.

- `Error` → If an invalid instruction or another error is encountered.

# Resources

Finding resources for this project was challenging, as we are the first cohort at our campus to face it.  

We consulted various external materials to better understand sorting strategies and optimization techniques, including:

- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- https://visualgo.net/en/sorting

We also used AI-based tools to:

- Debug specific implementation issues.
- Clarify algorithmic complexity concepts.
- Compare different sorting approaches and their theoretical performance.

# Contributions

Both of us have worked on implementing functions that are used in all the cases: *iarrien-* implemented the radix sort algorithm, the functions to collect the numbers for the different versions of the program input, the push swaps functions and bench flag options, and worked in most part of the checker (bonus part). *shierro* implemented the selection and turk sort algorithms, the validation for the input, the function for ordering three numbers, the merge sort for ordering indexes and the README file. All the other parts were done mostly together, implementing some of the range sort functions, deciding the way of ordering data with defining structs, etc.