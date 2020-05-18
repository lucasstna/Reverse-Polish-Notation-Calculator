# Reverse-Polish-Notation-Calculator
 This is a simple college assignment project, developed entirely in C langugage for the Algorithms and Programming II course. The main purpose of the project is to implement a [reverse-Polish notation](http://www.calculator.org/rpn.aspx) calculator.

## How does it work ?
  The program was made to show the ability of working with linked **queues** and **stacks**. With that in mind, the input is stored in a queue and when the operations starts, the values are dequeued and tested. If the value removed is an operand, it gets pushed in a stack. If it's not, the most recent values in the stack are popped and the operation is done, according to the operand.
  
## How can you use it ?
  Because the entyre project is made in C, the only thing necessary to run it in your computer is the **gcc** compiler.
  
### Input 
  The calculator works with a predefined input, as you can see in the example below. The first value is the number of expressions you want to solve, followed by them. All the expressions are followed by a '@' sign, indicating its ending.

```
 5
 1.0 2.0 + 2.5 - 2.5 * @
 5.0 +2.0 / 2.5 ^ 2.0 + L @
 +6.0 4.00 % -1.25 - ! -1.0 * @
 5.0 1.0 2.0 + 4.0 * + 3.0 - @
 1.0 2.0 + 4.0 * 5.0 + 3.0 - @
```

