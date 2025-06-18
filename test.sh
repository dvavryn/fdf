make re
make clean
clear
# ./fdf test_maps/42.fdf
valgrind --track-origins=yes ./fdf test_maps/42.fdf