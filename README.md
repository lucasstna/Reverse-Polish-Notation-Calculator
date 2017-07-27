# Reverse-Polish-Notation-Calculator
  This is simple project, developed entirely in C and made by me as college work for the discipline of Algorithms and Programming II. The main purpose of the project is to implement a calculator that uses the [reverse-Polish notation](http://www.calculator.org/rpn.aspx) as entry source.

## How does it works ?
  The program was made to show the ability of working with linked **queues** and **stacks**. With that in mind, the input is stored in a queue and when the operations start to be done, the values are removed from the queue and tested. If the value removed is an operand, it gets pushed in a stack. If it's not, the most recent values in the stack are popped and the operation is done, according to the operand.
  
## How can you use it ?
  Because the entyre project is made in C, the only thing that is necessary to run it in your computer is the **gcc** compiler.
  
  ### Input 
 The calculator works with an predefined input. The first value is the number of expressions you want to solve, followed by them. All the expressions have an '@' in the end indicating the end of the expression. Take a look at the example:

```
 5
 1.0 2.0 + 2.5 - 2.5 * @
 5.0 +2.0 / 2.5 ^ 2.0 + L @
 +6.0 4.00 % -1.25 - ! -1.0 * @
 5.0 1.0 2.0 + 4.0 * + 3.0 - @
 1.0 2.0 + 4.0 * 5.0 + 3.0 - @
```

