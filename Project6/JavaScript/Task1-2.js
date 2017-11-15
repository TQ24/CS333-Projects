// CS333 Project 6
// Part 2: File I/O
// JavaScript
// Tracy Quan
//
// read a file using fs (file system) module

var fs = require('fs');
fs.readFile('test.txt','utf8', function(err,data){
  if (err) throw err;
  console.log(data);
});
