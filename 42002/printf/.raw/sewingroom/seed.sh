# #to create folders needed to split printf
# # //[new structure]
# # ////////	TEMP:
# # ////main()	//for testing and calling the function pre-release	
# # ////////	ROOT:
# # ////ft_printf()		//the star of the show
# # ////ft_ptfcha()		//prints individual characters
# # ////ft_ptfstr()		//prints strings of characters
# # ////ft_ptfhex_put()		//practical printer of hex
# # ////////	UTIL:
# # ////ft_ptfvex()		//checks for flags and selects next ft
# # ////ft_uitoa()		//converts unsigned int to a string
# # ////ft_ptfnumlen()		//length-measure for int printing
# # ////ft_ptfhex_len()		//length-measure of hex number
# # ////////	SRC:
# # ////ft_ptfint()		//motherfunction for int printing
# # ////ft_ptfuin()		//motherfunction for uint printing
# # ////ft_ptfptr()		//motherfunction for pointer printing
# # ////ft_ptfhex()		//motherfunction for hex printing
# # ////////	BONUS:
# # ////()		//
# # ////()		//
# ft_printf
# ft_ptfcha
# ft_ptfstr
# ft_ptfhex_put
# ft_ptfvex
# ft_uitoa
# ft_ptfnumlen
# ft_ptfhex_len
# ft_ptfint
# ft_ptfuin
# ft_ptfptr
# ft_ptfhex
# # ////()		//
# /$sub_dir
# ft_printf.c
# Makefile
# # ////()		//
# /$sub_dir/LIB
# ft_printf.h
# libft.h
# Makefile
# #misc lib functions
# # ////()		//
# /$sub_dir/SRC
# ft_ptfint.c
# ft_ptfuin.c
# ft_ptfptr.c
# ft_ptfhex.c
# ft_ptfcha.c
# ft_ptfstr.c
# # ////()		//
# /$sub_dir/UTL
# ft_uitoa.c
# ft_ptfvex.c
# ft_ptfhex_put.c
# ft_ptfnumlen.c
# ft_ptfhex_len.c
# # ////()		//
# # ////	NOTES: [this setup is symmetrical, and mirrors the intended 4 x 4 array]

d_user ()
{
    
    echo "the following files are part of the creation" ; echo "" ; echo "" 
    if [] ; then d_event
    else    u_exit
    fi
}

u_init ()
{
    echo $(pwd)
    echo $(ls)
    m_intro
    u_exit
}

u_exit ()
{
    exit
}

m_intro ()
{
    echo "      based on the previous information"
    echo "would you like to go ahead with basic touching?"
    echo " "
    echo "                  y / n"
    read -r vm_intro
    if ! [ $vm_intro = "y"] || ! [ $vm_intro = "n"]
    u_exit
    elif [ $vm_intro = "y"] ; then vm_intro="yes"
        echo "very well, you have selected $vm_intro"
        d_user
    elif [ $vm_intro = "n"] ; then vm_intro="no"
        echo "very well, you have selected $vm_intro"
        u_exit
    fi
}



u_init

# # ////()		//
# echo ""
# /$sub_dir
# ft_printf.c
# Makefile
# # ////()		//
# /$sub_dir/LIB ft_printf.h libft.h Makefile
# #misc lib functions
# # ////()		//
# /$sub_dir/SRC ft_ptfint.c ft_ptfuin.c ft_ptfptr.c ft_ptfhex.c ft_ptfcha.c ft_ptfstr.c
# # ////()		//
# /$sub_dir/UTL ft_uitoa.c ft_ptfvex.c ft_ptfhex_put.c ft_ptfnumlen.c ft_ptfhex_len.c
# # ////()		//

# mkdir LIB && cd LIB ; touch ft_printf.h libft.h Makefile ; pwd ; ls
# cd .. ; mkdir SRC && cd SRC ; touch ft_ptfint.c ft_ptfuin.c ft_ptfptr.c ft_ptfhex.c ft_ptfcha.c ft_ptfstr.c ; pwd ; ls
# cd .. ; mkdir UTL && cd UTL ; touch ft_uitoa.c ft_ptfvex.c ft_ptfhex_put.c ft_ptfnumlen.c ft_ptfhex_len.c ; pwd ; ls