#! /usr/bin bash
# shellcheck shell=bash
#
##
###	takes a number argument and prints that number of numbered lines
##
#

##	vars
running=0

##	funcs
sh_intro()
{
	clear
	if [[ "$running" = "0" ]]; then
		echo -e "let's play: numberwang\n"
		running=1
	fi
	sh_lineout
}

sh_lineout()
{
	echo -e "[usage: {number}{options}] || [Q]"
	echo -e "[needed: enter a number of lines to print]\n[optional: enter a suffix to follow each number]"
	echo -e "[[] default - no punctuation]\n[[.] - dots]\n[[:] - colons]\n"
	read -r num opt
	opt=${opt:-""}
	if [[ "$num" = "q" ]] || [[ "$num" = "Q" ]]; then
		sh_outro
	elif ! [[ "$num" =~ ^[0-9]+$ ]]; then
    		echo "Please enter a valid number."
		sh_lineout
	fi
	clear
	for ((i=1; i<=num; i++)); do
		echo "$i$opt"
	done
}

sh_outro()
{
	echo -e "\n\nall done?\n\n[RETURN]\t[n]"
	read -r fin
	fin=${fin:-""}
	if [[ "$fin" != "n" ]] && [[ "$fin" != "N" ]]; then
		cd - || exit; clear ; exit
	else
		sh_lineout
	fi
}

##	calls
sh_intro
sh_outro