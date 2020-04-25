# fast-js
## Example of writing C++ modules for Node

1. make sure your have node 14.0.0 installed (or update the node engines variable with your version)
2. `$ npm install` or `$ npm i` (shorthand)
3. run the project with `$ npm start`

## What does it do?
This example aims to compare the speed at which we do the same operations in C++ and JavaScript.

The operations include the following:
- iterate over a large number count
- change a value of an number/integer on the program stack
- print a string of "hello\n" to standard output (stdout)

## Example output:
```
λ npm start

> fast-js@1.0.0 start C:\Users\tngam\source\repos\JS\fast-js
> node main.js

node_modules\nan
C++ count complete
hello from C++
C++ loop time (nanoseconds, measured in C++): 1045500ns
C++ call time (time it takes to call and run C++ code in JS): 4.244ms
JS count complete
hello from JS
JS loop time: 2.001s
```
Translation:
* C++ loop: **1.0455 ms** (milliseconds) or 1045500 ns (nanoseconds)
* C++ loop called from JS: **4.244 ms** (milliseconds)
* JS loop: **2001 ms** or 2.001 s (seconds)