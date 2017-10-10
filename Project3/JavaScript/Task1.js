/* Project3 Task1
 * Tracy Quan
 *
 *
 * JavaScript
 * Task1:Write an example program in each language that demonstrates the rules
 * for identifier naming, variable declarations and identifier scoping.
 * Focus on any special rules or capabilities of your language.
 */

var kobe = 24;	//Global variable

function go(){
	if (true){
    	var a = 6;
  	}
  	return a;		//The scope of variable a is within the function instead of within the if statement
}

function foo(){
	/* When we declare an identifier(variable) in JavaScript,
	 * we don't need to clarify the data type and we can change the datatype of variables any time.
	 */
	let kobe = 8;	//Local variable
	kobe = "KobeBryant";	//change the datatype of a variable
	return kobe;
}

alert(go());
alert(foo());
alert(kobe);
