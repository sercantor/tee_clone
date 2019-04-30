# This is a clone of tee program, which gets input from STDIN and outputs it to STDOUT and also the files that are given in the argument. 
##Project Description
  ###mytee f1 f2 f3 → reads stdin and outputs it to files in the argument, error if file(s) already exist
  ###mytee 	-a f1 f2 → append to files
  ###mytee -t f1 f2 → truncate and write to files
