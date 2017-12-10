// CS333
// Project 7
// JavaScript
// Task1

//-------------- Allocations ------------------

var number = 04901;    // allocates memory for a number
var str = 'Colby';     // allocates memory for a string

var object = {
  v1: 04901,
  v2: null
};                     // allocates memory for an object
                       // and contained values

var arr = [1,24,8,'cs'];  // allocates memory for an array

function func(a){      // allocates a function
  return 2*a;
}

//------------ Reference-counting garbage collection ----------------
var obj = {
  p1:{
    p1_p;
  }
};      // two objects are created:
        // one is referenced by the other as its property and the other is assigned to var obj

var o2 = obj;  // o2 is the second thing that has a reference to the object

obj = 1;    // now var obj lost its reference to the object. The object has unique reference o2.

var op = o2.p1;    // var op is another reference of the property p1 of the object
                    // now, the property p1 has two references

o2 = 'ha';          // Now, the object originall in obj lost its last reference,
                    // so it has zero reference and can be garbage collected.
                    // The property of the object p1 still has a reference var op, so it cannot be freed.

op = null;        // the property p1 of the original object lost its last reference,
                    // sp it can be freed as well.
