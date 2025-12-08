#finds all files within directory; wc (word count) is used as a counter, with -l specified as a flag for counting lines
find -type 'd,f' | wc -l
