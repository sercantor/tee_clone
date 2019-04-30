##Project Description
  - **mytee f1 f2 f3 **→ reads stdin and outputs it to files in the argument, error if file(s) already exist
  - **mytee 	-a f1 f2** → append to files
  - **mytee -t f1 f2** → truncate and write to files

------------

###The Challenge
- Because the program writes to multiple files, it can be tricky to play with file descriptor array
- Figuring out where to stop the reading of standart input, solved by **reading the manual**

------------

###What Could Be Improved Upon
- I use reference to pass around file descriptor array, which means I don't iterate every element of the array, this could cause safety problems

------------
