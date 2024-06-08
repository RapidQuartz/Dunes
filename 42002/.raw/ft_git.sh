#!/env/bin sh
# shellcheck shell=dash

### functional git utility

## TODO
# create git assigning function
# create interface to get git stuff
# make it interchangeable

## Variables
i=0
## Functions

## u_

u_init()
{
	m_1;
}

u_exit()
{
	if [ $i ] ; then clear ; echo "the end\n"
	sleep 1 ; clear ; zsh && exit
	else u_init
	fi
}

## m_

m_1()
{
	printf "it seems you require some git \
	that would be ever so delightful \
	won't you please paste your git link or choose another option?\n" ;
	printf "" ;
	read -r tea ; if [ $tea = "" ] ; then d_tea
		elif [ $tea = "1" ] ; then printf "hello \
		it is lovely to  see you again \
		won't you come inside and have some tea?\n" 
		elif [ $tea = "2" ] ; then printf "hello \
		it is lovely to  see you again\
		won't you come inside and have some tea?\n" 
		elif [ $tea = "3" ] ; then printf "hello \
		it is lovely to  see you again\
		won't you come inside and have some tea?\n" ; fi
	read -r tea ; if [ $tea = "thx" ] ; then tea ; fi
}

## d_

d_tea()
{
	printf "thank you for coming for tea \
	it was ever so delightful";
	i=1
	u_exit
}
## Script
u_init
u_exit
## Comments

# Structure:
# u_	utility functions
# m_	menu functions
# d_	directory functions
