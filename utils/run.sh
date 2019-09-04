inc_opt=-I/home/tinychong/work/leetcode/utils
opt=-g 
echo gcc $1.c $opt $inc_opt  -o $1
gcc $1.c $opt $inc_opt -o $1
