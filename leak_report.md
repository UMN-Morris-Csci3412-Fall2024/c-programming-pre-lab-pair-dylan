# Leak report

The memory leaks in check_whitespaces.c was in the strip function.
It allocated memory useing calloc but never freed said allocated memory.
This created a memory leak every time the strip function was called.
To fix this problem I made sure that the caller of strip was responsible for freeing the memory.
Is_clean calls strip so it is the one responsible for freeing the memory thus fixing the memory leaks.