require('nan')
const { hello } = require('./build/Release/hello.node');

const cPlusPlusHelloTime = "C++ call time (time it takes to call and run C++ code in JS)"
console.time(cPlusPlusHelloTime);
hello();
console.timeEnd(cPlusPlusHelloTime);

const jsLoopTime = "JS loop time";
console.time(jsLoopTime);
let count = 0;
for (let i = 0; i < 1_000_000_000; i++) {
    count = i;
    if (count == 999_999_999)
    {
      console.log("JS count complete");
    }
}
console.log("hello from JS");
console.timeEnd(jsLoopTime);