# Expression Evaluator

A powerful C++ expression evaluator that converts infix mathematical expressions to postfix (Reverse Polish) notation and evaluates them using a stack-based algorithm.

## Features
- **Infix to Postfix Conversion**: Implements the Shunting-yard algorithm.
- **Operator Support**: Supports `+`, `-`, `*`, `/`, and `^` (exponentiation).
- **Advanced Syntax**: Handles parentheses, multi-digit numbers, and floating-point values.
- **Interactive REPL**: Enter expressions one by one and see both the postfix notation and the final result.
- **Error Handling**: Detects mismatched parentheses, division by zero, and invalid characters.

## How to Run

### Compilation
Compile the source code using `g++`:

```bash
g++ main.cpp -o expr_eval
```

### Execution
Run the compiled executable:

```bash
./expr_eval
```

## Example Usage

```bash
========================================
       EXPRESSION EVALUATOR
========================================

  Supported operators: + - * / ^
  Supports: parentheses, multi-digit
            numbers, floating point

  Type "exit" to quit

----------------------------------------
  Enter infix expression: 2 + 3 * 4

  Postfix: 2 3 4 * + 
  Result:  14
----------------------------------------
  Enter infix expression: (10 + 2) / 3

  Postfix: 10 2 + 3 / 
  Result:  4
----------------------------------------
  Enter infix expression: 2 ^ 3

  Postfix: 2 3 ^ 
  Result:  8
----------------------------------------
  Enter infix expression: exit

  Goodbye!
```
