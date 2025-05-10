#!/usr/bin sh
# shellcheck shell=dash
root=/home/akjoerse/42/006_FdF/repo/
bak="$root"kladd/.old/
b_src="$root""$bak"src
b_old="$b_src".old
b_doc="$root""$bak".doc
r_src="$root"src
r_doc="$root".doc
#
main()
{
	if [ ! -d "$b_src" ]; then
		mkdir "$b_src" || exit
	fi
	if [ ! -d "$b_doc" ]; then
		mkdir "$b_doc"
	fi
	if [ ! -d "$r_doc" ]; then
		mkdir "$r_doc"
	fi
	if [ ! -d "$b_old" ]; then
		make_old
	fi
	if [ -d "$b_old" ]; then
		mv "$r_src"*.c "$b_old"/src
	fi
	if [ ! -d "$b_src""parsing" ]; then
		mkdir "$b_src"parsing
	fi
	if [ ! -d "$b_src""utility" ]; then
		mkdir "$b_src"utility
	fi
	if [ ! -d "$b_src""drawing" ]; then
		mkdir "$b_src"drawing
	fi
	if [ ! -e "$b_src""parsing/parse_mapfile.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"parsing/parse_mapfile.c
	fi
	if [ ! -e "$b_src""parsing/create_map.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"parsing/create_map.c
	fi
	if [ ! -e "$b_src""utility/get_dimensions.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"utility/get_dimensions.c
	fi
	if [ ! -e "$b_src""utility/line_start.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"utility/line_start.c
	fi
	if [ ! -e "$b_src""utility/line_end.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"utility/line_end.c
	fi
	if [ ! -e "$b_src""drawing/draw_map.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"drawing/draw_map.c
	fi
	if [ ! -e "$b_src""drawing/draw_vline.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"drawing/draw_vline.c
	fi
	if [ ! -e "$b_src""drawing/draw_hline.c" ]; then
		echo "# include \"../FdF.h\"" >> "$b_src"drawing/draw_hline.c
	fi
	if [ ! -e "$r_doc""parsing.md" ]; then
		echo "#\t[README](../README.md#)  \n" >> "$r_doc"parsing.md
	fi
	if [ ! -e "$r_doc""drawing.md" ]; then
		echo "#\t[README](../README.md#)  \n" >> "$r_doc"drawing.md
	fi
	if [ ! -e "$r_doc""utility.md" ]; then
		echo "#\t[README](../README.md#)  \n" >> "$r_doc"utility.md
	fi
}

make_old()
{
	if [ -d ".old" ]; then
		echo "\".old\" folder found at $(pwd). going deeper"
		while [ -d ".old" ]; do
			cd .old || exit
		done
	fi
	if [ ! -d ".old" ]; then
		echo "no \".old\" folder found at $(pwd). making now"
		mkdir ".old" || exit
		cd .old || exit
	fi
	if [ ! -d "src" ]; then
		echo "no \"src\" folder found at $(pwd). making now"
		mkdir "src" || exit
	fi
	b_old=$(pwd)
	cp "$r_src"*.c "$b_old"
	echo "copied files to""$b_old"
}