// CS333 Project 6
// Part 2: File I/O
// JavaScript
// Tracy Quan
//
// Word Counter

var fs = require('fs');
var file = 'wctest.txt';

// split string by whitespace
function split(text){
  var wordsarr = text.split(/\s+/);
  return wordsarr;
}

// create word-key pair for each word in the list
function createWordMap(words){
  var map = {};

  words.forEach(function (key){
    if (map.hasOwnProperty(key)) {
      map[key]++;
    }
    else{
      map[key]=1;
    }
  });

  return map;
}

// sort the list according to the count of words.
function sort(words){
  var finallst = [];
  finallst = Object.keys(words).map(function(key){
    return{
      word: key,
      count: words[key]
    }
  });

  finallst.sort(function(a,b){
    return b.count-a.count;
  });

  return finallst;
}

// read files
fs.readFile(file, 'utf8', function(err, data){
  if (err) throw err;

  var words = split(data.toLowerCase().replace(/[^\w\s]|_/g,""));
  var map = createWordMap(words);
  var finallst = sort(map);

  var i = 0;
  for (i; i<20; i++){
    console.log("Word:" + finallst[i].word + "  Count:" +finallst[i].count);
  }
  //console.log(finallst);
});
