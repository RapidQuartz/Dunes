[MAIN LOG](log.md)
[README](README.md)
[TODO](TODO.md)
[MAKEFILE](logmakefile.md)
[HERE](logbugs.md)

[#bughunt](#bughunt)
#	bughunt
<raw dump from make attempt at 2025-01-23 15:36:48>
<!-- <raw dump from make attempt at 2025-01-23 15:36:48>
c3a6c4% make
cc -g -c algorithm.c -o algorithm.o -I push_swap.h
algorithm.c:273:25: error: too few arguments to function call, expected 3, have 2
                        dosort_def(stack_a, i);
                        ~~~~~~~~~~           ^
algorithm.c:20:7: note: 'dosort_def' declared here
void            dosort_def(t_stack **stack, t_stack **kcats, int flag);
                ^
algorithm.c:292:12: error: too few arguments to function call, expected 2, have 0
                dd(do_pb(), (*stack), (*kcats));
                   ~~~~~ ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:293:9: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_pb((*stack), (*kcats));
                      ^~~~~~~~
                      &
./push_swap.h:42:23: note: passing argument to parameter 'stack_a' here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                                ^
algorithm.c:293:19: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_pb((*stack), (*kcats));
                                ^~~~~~~~
                                &
./push_swap.h:42:42: note: passing argument to parameter 'stack_b' here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                                                   ^
algorithm.c:297:17: error: too few arguments to function call, expected 2, have 1
                do_pb((*stack));
                ~~~~~         ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:298:9: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_sa((*stack));
                      ^~~~~~~~
                      &
./push_swap.h:44:23: note: passing argument to parameter 'stack' here
void            do_sa(t_stack **stack);
                                ^
algorithm.c:299:12: error: too few arguments to function call, expected 2, have 0
                dd(do_pb(), (*stack), (*kcats));
                   ~~~~~ ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:303:9: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_sa((*stack));
                      ^~~~~~~~
                      &
./push_swap.h:44:23: note: passing argument to parameter 'stack' here
void            do_sa(t_stack **stack);
                                ^
algorithm.c:304:12: error: too few arguments to function call, expected 2, have 0
                dd(do_pb(), (*stack), (*kcats));
                   ~~~~~ ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:305:17: error: too few arguments to function call, expected 2, have 1
                do_pb((*stack));
                ~~~~~         ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:312:3: warning: implicit declaration of function 'do_rotate' is invalid in C99 [-Wimplicit-function-declaration]
                do_rotate((*stack));
                ^
algorithm.c:313:11: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_swap((*stack));
                        ^~~~~~~~
                        &
./push_swap.h:43:25: note: passing argument to parameter 'stack' here
void            do_swap(t_stack **stack);
                                  ^
algorithm.c:314:3: warning: implicit declaration of function 'do_push' is invalid in C99 [-Wimplicit-function-declaration]
                do_push((*stack));
                ^
algorithm.c:315:3: warning: implicit declaration of function 'do_reverse' is invalid in C99 [-Wimplicit-function-declaration]
                do_reverse((*stack));
                ^
algorithm.c:316:12: error: too few arguments to function call, expected 2, have 0
                dd(do_pb(), (*stack), (*kcats));
                   ~~~~~ ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:320:11: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_swap((*stack));
                        ^~~~~~~~
                        &
./push_swap.h:43:25: note: passing argument to parameter 'stack' here
void            do_swap(t_stack **stack);
                                  ^
algorithm.c:321:3: warning: implicit declaration of function 'do_push' is invalid in C99 [-Wimplicit-function-declaration]
                do_push((*stack));
                ^
algorithm.c:322:11: warning: incompatible pointer types passing 't_stack *' (aka 'struct s_stack *') to parameter of type 't_stack **' (aka 'struct s_stack **'); take the address with & [-Wincompatible-pointer-types]
                do_swap((*stack));
                        ^~~~~~~~
                        &
./push_swap.h:43:25: note: passing argument to parameter 'stack' here
void            do_swap(t_stack **stack);
                                  ^
algorithm.c:323:12: error: too few arguments to function call, expected 2, have 0
                dd(do_pb(), (*stack), (*kcats));
                   ~~~~~ ^
./push_swap.h:42:7: note: 'do_pb' declared here
void            do_pb(t_stack **stack_a, t_stack **stack_b);
                ^
algorithm.c:327:3: warning: implicit declaration of function 'do_do_rotate' is invalid in C99 [-Wimplicit-function-declaration]
                do_do_rotate((*stack));
                ^
algorithm.c:328:3: warning: implicit declaration of function 'do_rotate' is invalid in C99 [-Wimplicit-function-declaration]
                do_rotate((*stack));
                ^
algorithm.c:329:3: warning: implicit declaration of function 'do_push' is invalid in C99 [-Wimplicit-function-declaration]
                do_push((*stack));
                ^
algorithm.c:330:3: warning: implicit declaration of function 'do_reverse' is invalid in C99 [-Wimplicit-function-declaration]
                do_reverse((*stack));
                ^
15 warnings and 8 errors generated.
make: *** [Makefile:28: algorithm.o] Error 1
 -->
</raw dump from make attempt at 2025-01-23 15:36:48>
[]()
#