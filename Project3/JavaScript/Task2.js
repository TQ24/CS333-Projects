/* Project3 Task2
 * Tracy Quan
 *
 *
 * JavaScript
 * Task2: Write an example program in each language that executes a binary search
 * on a list or array of numbers.
 */

// return the index of the target item if found, return -1 if not found.
function binary_search(list, item){
  var min_index = 0;
  var max_index = list.length - 1;
  var guess_index;

  while (min_index <= max_index){
    guess_index = Math.floor((min_index + max_index)/2);
    if (list[guess_index] == item){
      return guess_index;
    }
    else if (list[guess_index] > item) {
      max_index = guess_index - 1;
    }
    else{
      min_index = guess_index + 1;
    }
  }

  return -1;

}

alert("The Index of 8 is " + binary_search([2,4,8,16,32,64,128,256,512,1024,2048],8));
alert("The Index of 1024 is " + binary_search([2,4,8,16,32,64,128,256,512,1024,2048],1024));
