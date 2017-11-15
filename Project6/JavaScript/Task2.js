// CS333 Project 6
// Part 2: File I/O
// JavaScript
// Tracy Quan
//
// Explore the functions of JavaScript

// function without return
console.log("Return type of functions in JavaScript ----");

function add_woreturn(a,b){
  console.log("add_woreturn: ",a+b);
};

// function with return
function add_wreturn(a,b){
  return a+b;
};

add_woreturn(24,8);
console.log("add_wreturn: ",add_wreturn(24,8))

// ---------------------------------------------
// test how JavaScript handles function overload (with same number of arguments)
console.log("Functions overload in JavaScript----");

function overload(a, b){
  console.log("overload function test 1:",a-b);
};

function overload(a, b){
  console.log("overload function test 1:",a+b);
};

overload(24,8);

// test how JavaScript handles function overload (with different number of arguments)
function overload2(a,b){
  console.log("overload function test 2:", a+b);
};

function overload2(a,b,c){
  console.log("overload function test 2:", a+b+c);
};

overload2(8,24);


// ---------------------------------------------
// Can you create functions with an unknown number of arguments? How do you access those arguments?

function sum(list){
  var l = arguments.length;
  var sum = 0;
  for (var i = 0; i < l; i++){
    sum = sum + arguments[i];
  }
  console.log("Exploring arguments in JavaScript------");
  console.log("Sum: ", sum);
}

sum(1,2,3,4,5);

// ---------------------------------------------
// Can you dynamically create functions? If so, how?
console.log("Create functions dynamically in JavaScript----");

var adder = new Function( 'a', 'b', 'return a+b');
console.log(adder(24,8));

// ---------------------------------------------
// What mechanism exists for publishing the existence of a function to other functions or compilable units (e.g. files)?

module.exports = sum;
