/* Project3 Task3
 * Tracy Quan
 *
 *
 * JavaScript
 * Task3: Write an example program in each language that demonstrates all of the
 * basic built-in types and how to construct aggregate types (e.g., records, classes or structures).
 */
 var output1;
 var output2;
 var output3;
 var output4;
 var output5;
 var output6;

function foo(){
  var int = 24;
  var int_2 = 8;
  var str = "Number";
  output1 = str+int;
  output2 = str+int+int_2;
  output3 = int+int_2+str;
  output4 = str*int_2;
  output5 = 24/8;
  output6 = (int == int_2);
}

foo();
alert("Output1 of foo(): " + output1);
alert("Output2 of foo(): " + output2);
alert("Output3 of foo(): " + output3);
alert("Output4 of foo(): " + output4);
alert("Output5 of foo(): " + output5);
alert("Output6 of foo(): " + output6);

/* ---------------------------------------------------------
 * Build a class in JavaScript. (Methods defined internally)
 */
function Player(position){
  this.position = position;
  this.team = "Lakers";
  this.getInfo = function(){
    return this.position + " of " + this.team;
  }
}

var player = new Player("ShootingGuard");
alert("Player Info: "+ player.getInfo());


/* ---------------------------------------------------------
 * Build a class in JavaScript. (Methods added to the prototype)
 */
function Game(result){
  this.team = "Lakers";
  this.result = result;
}

Game.prototype.getInfo = function(){
  return this.team + " " + this.result + "s.";
};

var result = new Game("win");
alert(result.getInfo());
