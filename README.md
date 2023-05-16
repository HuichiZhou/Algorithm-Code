# Algorithm-Code
记录算法刷题日常
## quick_sort边界问题
当x=q[l]时,  
quick_sort(q, l, i-1);  
quick_sort(q, i, r);  
上述两个式子不能使用i，而要使用j,j+1。  

反之，
当x=q[r]时,  
quick_sort(q, l, j);  
quick_sort(q, j+1, r);  
上述两个式子不能使用j，而要使用i-1,i。  
