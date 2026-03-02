
# 🎯 Functions, Procedures, Return Types, Parameters, and Global Variables in C++

## Introduction

In this study, we'll review the main concepts of **functions**, **procedures**, **return types**, **ways to pass parameters**, and the use of **global variables** in C++.  
All of this is applied in a practical code example to ensure understanding both theoretically and practically — perfect for exams and projects.

# 📘 1. Fundamental Concepts

## 1.1 What are Functions and Procedures?

- **Procedure** is a function that **does not return a value** (type `void`). It only performs an action, like printing something on the screen.
- **Function** is a block of code that **returns a value**. It can return `int`, `float`, `char`, `string`, pointer, struct, object, and more.

**Importance:**  
Dividing the program into functions and procedures makes the code **more organized**, **reusable**, and **easier to maintain**.

---

## 1.2 Function Structure

A standard function in C++ consists of:

- **Return type**: The type of data returned (or `void` if there is no return).
- **Function name**: A clear and descriptive name.
- **Parameters**: Values that the function needs to work with.
- **Function body**: A set of commands enclosed by `{}`.

Variables declared inside a function are **local**: they only exist within that function.

# 🛠️ 2. Functions in Code

In the example code, we have various types of functions:

## 2.1 Procedure: Displaying a Menu

```cpp
void writeMenu()
```

- Prints a small menu of options to the console.
- **Does not return anything**, just executes the action.

---

## 2.2 Functions with Return Types

Code examples:

| Return Type | Function | Explanation |
|:-|:-|:-|
| `int` | `calculateFactorial(int x)` | Calculates the factorial of a number using a `while` loop. |
| `int` | `sum(int a, int b)` | Returns the sum of two integers. |
| `float` | `average(float a, float b)` | Calculates and returns the average. |
| `bool` | `isEven(int num)` | Returns `true` if the number is even. |
| `char` | `firstCharacter(string str)` | Returns the first character of a string. |
| `int*` | `findMax(int arr[], int size)` | Returns a **pointer** to the largest element in an array. |
| `int&` | `greaterNumber(int& a, int& b)` | Returns a **reference** to the greater of two numbers. |
| `Point` (struct) | `createPoint(int x, int y)` | Returns an object of type `Point` (x, y). |
| `Person` (class) | `createPerson(string name, int age)` | Returns an object of class `Person`. |
| `string` | `greeting()` | Returns a welcome message. |

---

# 🔗 3. Return Types

Here’s a summary of possible return types in functions:

- **Primitive types**: `int`, `float`, `char`, `double`, etc.
- **Pointers**: like `int*`, to return memory addresses.
- **References**: like `int&`, to avoid unnecessary copying.
- **Structs and Classes**: return complete objects, useful for organizing data.
- **Strings**: using `std::string` to work with text.

⚡ Important: Functions that return values **must have** a `return` statement.

---

# 🚀 4. Function Calls

There are two main types of function calls in the code:

## 4.1 Direct Calls

Functions like `function1()`, `function2()`, `function3()` are called directly in the `main()`.  
These functions can even call each other (e.g., `function3()` calls `function1()` and `function2()`).

## 4.2 Global Function Calls

Some functions are **declared first** (with `void name();`) and **defined later** in the code.  
However, C++ allows these functions to be called anywhere after their declaration.

---

# 🌍 5. Global Variables

- `globalVariable` is an integer declared **outside** of any function.
- Any function can access (and modify, if needed) it.
- Example in code: `function4()` uses the global variable.

⚠️ **Caution:** Overusing global variables can lead to hard-to-find bugs.

---

# 🔄 6. Parameters: By Value vs. By Reference

## 6.1 By Value

```cpp
void doubleValue(int number)
```

- The function receives a **copy** of the original value.
- Modifications **do not affect** the value outside the function.

**Example in `main()`:**

- Before calling `doubleValue(value1)`, `value1 = 10`.
- After the call, `value1` is still 10.

---

## 6.2 By Reference (with Pointer)

```cpp
void doubleValueByReference(int* number)
```

- The function receives the **address** of the variable.
- Modifies the original value directly.

**Example in `main()`:**

- Before calling `doubleValueByReference(&value2)`, `value2 = 10`.
- After the call, `value2 = 20`.

**Summary:**  

- **Pass by value** → **copy** (does not modify).
- **Pass by reference** → **address** (modifies the original).

---

# 🧠 7. Step-by-Step Execution of `main()`

In `main()`, the flow is:

1. Write the menu (`writeMenu()`).
2. Calculate the factorial of 5 and display it.
3. Test functions with different return types.
4. Work with arrays (find the maximum number).
5. Use structs and classes (`Point`, `Person`).
6. Print a greeting.
7. Make direct and global function calls.
8. Test the global variable.
9. Show the difference between pass by value and pass by reference.

---

# 📝 SUMMARY

- **Procedures** perform actions without returning values.
- **Functions** perform actions and return values.
- There are **different return types**.
- **Parameters** can be passed by **value** or **reference**.
- **Global variables** are accessible throughout the program (but should be used cautiously).

---

# 🚀 Final Tip

For exams and projects:

- Always think about **breaking** your code into small, clear functions.
- Prefer **pass by value** when you don’t need to modify the original data.
- Use **pass by reference** for performance gains or when modifying values.
- Keep control over the use of **global variables** to avoid confusion.
