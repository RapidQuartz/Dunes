#!/usr/bin sh
# shellcheck shell=dash
echo "# include \"../../FdF.h\"" >> src/parsing/parse_mapfile.c
echo "# include \"../../FdF.h\"" >> src/parsing/create_map.c
echo "# include \"../../FdF.h\"" >> src/utility/get_dimensions.c
echo "# include \"../../FdF.h\"" >> src/utility/line_start.c
echo "# include \"../../FdF.h\"" >> src/utility/line_end.c
echo "# include \"../../FdF.h\"" >> src/drawing/draw_map.c
echo "# include \"../../FdF.h\"" >> src/drawing/draw_vline.c
echo "# include \"../../FdF.h\"" >> src/drawing/draw_hline.c