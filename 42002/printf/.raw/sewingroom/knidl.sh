# knidl
## a needle to sew together the printf project
###
##
#
var=-1
num=0
ite=0
neg=-1
global_power="on"
global_latch="off"
#
usr="default"
#
##
###
##
#

#
u_init ()
{
	if [ $global_latch = "on" ] ; then
		cd ~/42/!Dunes || mkdir ~/42/!Dunes || u_err
	fi
	m_intro
}
u_exit ()
{
    echo "the end" ; exit
}
#
d_user ()
{
    if ! [ $usr = "default" ] ; then echo "greetings $usr" && m_user ; fi
	if [ $usr = "default" ] ; then echo "enter your name" && read -r usr ; d_user ; fi
}

d_menu ()
{
    echo "your choice indicates you wish to know more"
	path=(pwd)
	echo "$path"
	u_exit
}

d_event ()
{
    u_exit
}

d_twist ()
{
    u_exit
}
#

m_intro ()
{
	echo "[intro menu]"
	echo "[1 - user]" ; 	echo "[2 - event]" ; 	echo "[3 - twist]"
	read -r var
	echo "$var"
	if [ $var = "1" ] ; then
		echo "1/1" ; d_user
    elif [ $var = "2" ] ; then
		echo "1/2" ; d_event
    elif [ $var = "3" ] ; then
		echo "1/3" ; d_twist
	elif [ $var = "" ] || [ $var = -1 ] ; then
		echo "1/4" ; d_menu
	else echo "1/5" ; e_rr	
	fi
}

m_user ()
{
	echo "feature creep. Sorry."
}

# m_event ()
# {
    
# }

# m_twist ()
# {
    
# }

# m_outro ()
# {
    
# }
#

e_rr ()
{
	echo "seems something has gone wrong here."
	if [ $global_power = "off" ] || [ $global_latch = "off" ] ; then
		echo "let's see how wrong"
	elif [ $global_power = "off" ] || [ $global_latch = "on" ] ; then 
		echo "oh… oh dear…"
	fi
	echo "nothing for it. Exiting."
	u_exit
}

#
#
##
###
##
#
u_init
u_exit
#
##
###
##
#
