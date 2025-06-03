
##	[2025.06.03 13:07](valdump.md#20250603-1307)  
##	[clear text 2025.06.03 13:07](valdump.md#clear-text)  
###	[get_next_line](valdump.md#1)  
###	[ft_split: ' '](valdump.md#2)  
###	[get_next_line](valdump.md#3)  
###	[ft_split: '\n'](valdump.md#4)  
###	[ft_strjoin](valdump.md#5)  
##	[raw log 2025.06.03 13:07](valdump.md#raw-dump-logs)  

#	2025.06.03 13:07

##	clear text
5 errors  
 LEAK SUMMARY:  
    definitely lost: 5,361 bytes in 241 blocks  
    indirectly lost: 0 bytes in 0 blocks  
      possibly lost: 0 bytes in 0 blocks  
    still reachable: 115,192 bytes in 123 blocks  
         suppressed: 0 bytes in 0 blocks  
 Reachable blocks (those to which a pointer was found) are not shown.  
 To see them, rerun with: --leak-check=full --show-leak-kinds=all  
   
 For lists of detected and suppressed errors, rerun with: -s  
 ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 1 from 1)  

###	1
==153367== 57 bytes in 1 blocks are definitely lost in loss record 23 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==153367==    by 0x40473C: gnl_line (get_next_line.c:72)
==153367==    by 0x404536: get_next_line (get_next_line.c:27)
==153367==    by 0x403803: init_raw (init.c:56)
==153367==    by 0x40256F: main (fdf.c:47)
###	2
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403D65: ft_split (ft_split.c:38)
==153367==    by 0x402D3C: set_points (parse.c:96)
==153367==    by 0x4038D4: init_raw (init.c:70)
==153367==    by 0x40256F: main (fdf.c:47)
###	3
==153367== 570 bytes in 10 blocks are definitely lost in loss record 48 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==153367==    by 0x40473C: gnl_line (get_next_line.c:72)
==153367==    by 0x404536: get_next_line (get_next_line.c:27)
==153367==    by 0x403819: init_raw (init.c:59)
==153367==    by 0x40256F: main (fdf.c:47)
###	4
==153367== 616 bytes in 11 blocks are definitely lost in loss record 49 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403D65: ft_split (ft_split.c:38)
==153367==    by 0x403851: init_raw (init.c:64)
==153367==    by 0x40256F: main (fdf.c:47)
###	5
==153367== 3,650 bytes in 10 blocks are definitely lost in loss record 57 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403BBC: ft_strjoin (ft_strjoin.c:26)
==153367==    by 0x40383A: init_raw (init.c:62)
==153367==    by 0x40256F: main (fdf.c:47)

<!-- 2025.06.03 13:12:07	--leak-check=full
c3a7c2% valgrind --leak-check=full ./fdf test_maps/42.fdf                      
==153367== Memcheck, a memory error detector
==153367== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==153367== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==153367== Command: ./fdf test_maps/42.fdf
==153367== 
==153367== 
==153367== HEAP SUMMARY:
==153367==     in use at exit: 120,553 bytes in 364 blocks
==153367==   total heap usage: 1,360 allocs, 996 frees, 172,047 bytes allocated
==153367== 
==153367== 57 bytes in 1 blocks are definitely lost in loss record 23 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==153367==    by 0x40473C: gnl_line (get_next_line.c:72)
==153367==    by 0x404536: get_next_line (get_next_line.c:27)
==153367==    by 0x403803: init_raw (init.c:56)
==153367==    by 0x40256F: main (fdf.c:47)
==153367== 
==153367== 468 bytes in 209 blocks are definitely lost in loss record 46 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403D65: ft_split (ft_split.c:38)
==153367==    by 0x402D3C: set_points (parse.c:96)
==153367==    by 0x4038D4: init_raw (init.c:70)
==153367==    by 0x40256F: main (fdf.c:47)
==153367== 
==153367== 570 bytes in 10 blocks are definitely lost in loss record 48 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==153367==    by 0x40473C: gnl_line (get_next_line.c:72)
==153367==    by 0x404536: get_next_line (get_next_line.c:27)
==153367==    by 0x403819: init_raw (init.c:59)
==153367==    by 0x40256F: main (fdf.c:47)
==153367== 
==153367== 616 bytes in 11 blocks are definitely lost in loss record 49 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403D65: ft_split (ft_split.c:38)
==153367==    by 0x403851: init_raw (init.c:64)
==153367==    by 0x40256F: main (fdf.c:47)
==153367== 
==153367== 3,650 bytes in 10 blocks are definitely lost in loss record 57 of 64
==153367==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==153367==    by 0x403BBC: ft_strjoin (ft_strjoin.c:26)
==153367==    by 0x40383A: init_raw (init.c:62)
==153367==    by 0x40256F: main (fdf.c:47)
==153367== 
==153367== LEAK SUMMARY:
==153367==    definitely lost: 5,361 bytes in 241 blocks
==153367==    indirectly lost: 0 bytes in 0 blocks
==153367==      possibly lost: 0 bytes in 0 blocks
==153367==    still reachable: 115,192 bytes in 123 blocks
==153367==         suppressed: 0 bytes in 0 blocks
==153367== Reachable blocks (those to which a pointer was found) are not shown.
==153367== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==153367== 
==153367== For lists of detected and suppressed errors, rerun with: -s
==153367== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 1 from 1) -->

##	raw dump logs
<!-- 2025.06.03 13:07:01 --leak-check=full --show-leak-kinds=all
c3a7c2% valgrind --leak-check=full --show-leak-kinds=all ./fdf test_maps/42.fdf
==145707== Memcheck, a memory error detector
==145707== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==145707== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==145707== Command: ./fdf test_maps/42.fdf
==145707== 
^[==145707== 
==145707== HEAP SUMMARY:
==145707==     in use at exit: 120,529 bytes in 363 blocks
==145707==   total heap usage: 1,362 allocs, 999 frees, 172,099 bytes allocated
==145707== 
==145707== 3 bytes in 1 blocks are still reachable in loss record 1 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4B5458E: strdup (strdup.c:42)
==145707==    by 0x489FB45: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 8 bytes in 1 blocks are still reachable in loss record 2 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4B5458E: strdup (strdup.c:42)
==145707==    by 0x489C9AE: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x49B6820: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 8 bytes in 1 blocks are still reachable in loss record 3 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B4B34: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69DF: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 10 bytes in 1 blocks are still reachable in loss record 4 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4B5458E: strdup (strdup.c:42)
==145707==    by 0x489C9AE: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x4906213: XkbUseExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48A06A8: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 16 bytes in 1 blocks are still reachable in loss record 5 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4CE62EE: xcb_connect_to_fd (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE6E6B: xcb_connect_to_display_with_auth_info (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x48AFEE9: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 21 bytes in 1 blocks are still reachable in loss record 6 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A003E: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 24 bytes in 1 blocks are still reachable in loss record 7 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B6041: XextCreateExtension (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B64CC: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69C8: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 24 bytes in 1 blocks are still reachable in loss record 8 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4B5458E: strdup (strdup.c:42)
==145707==    by 0x489C9AE: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x49B6820: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B650A: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69C8: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 24 bytes in 1 blocks are still reachable in loss record 9 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B69F5: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 29 bytes in 1 blocks are still reachable in loss record 10 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48990CD: _XUpdateAtomCache (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489B929: XInternAtom (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404F62: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 32 bytes in 1 blocks are still reachable in loss record 11 of 63
==145707==    at 0x48487A9: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4CEA15E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA237: xcb_get_extension_data (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA2EE: xcb_prefetch_maximum_request_length (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA364: xcb_get_maximum_request_length (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x48A052B: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 32 bytes in 1 blocks are still reachable in loss record 12 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4CE31B7: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE3A08: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE3EB0: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE4E44: xcb_wait_for_reply (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA292: xcb_get_extension_data (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA2EE: xcb_prefetch_maximum_request_length (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CEA364: xcb_get_maximum_request_length (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x48A052B: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 32 bytes in 1 blocks are still reachable in loss record 13 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B67FF: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 32 bytes in 1 blocks are still reachable in loss record 14 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B67FF: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B650A: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69C8: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 33 bytes in 1 blocks are still reachable in loss record 15 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48990CD: _XUpdateAtomCache (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489B929: XInternAtom (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404F4B: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 40 bytes in 1 blocks are still reachable in loss record 16 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B01F1: _XPollfdCacheInit (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FE71: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 44 bytes in 1 blocks are still reachable in loss record 17 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4034C5: init_img (init.c:8)
==145707==    by 0x402599: main (fdf.c:51)
==145707== 
==145707== 48 bytes in 1 blocks are still reachable in loss record 18 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4036E5: init_mlx (init.c:33)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 48 bytes in 1 blocks are still reachable in loss record 19 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48AFE71: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 48 bytes in 1 blocks are still reachable in loss record 20 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48AFE87: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 48 bytes in 1 blocks are still reachable in loss record 21 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FE4C0: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 57 bytes in 1 blocks are definitely lost in loss record 22 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==145707==    by 0x40473C: gnl_line (get_next_line.c:72)
==145707==    by 0x404536: get_next_line (get_next_line.c:27)
==145707==    by 0x403803: init_raw (init.c:56)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 72 bytes in 1 blocks are still reachable in loss record 23 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489FF20: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 72 bytes in 1 blocks are still reachable in loss record 24 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FE4A4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 88 bytes in 1 blocks are still reachable in loss record 25 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x40388F: init_raw (init.c:67)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 88 bytes in 1 blocks are still reachable in loss record 26 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x40556B: mlx_int_new_xshm_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x405892: mlx_new_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4037B0: init_mlx (init.c:46)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 112 bytes in 1 blocks are still reachable in loss record 27 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48AFD72: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 112 bytes in 1 blocks are still reachable in loss record 28 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A0200: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 128 bytes in 1 blocks are still reachable in loss record 29 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A012E: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 128 bytes in 1 blocks are still reachable in loss record 30 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489C99E: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x4906213: XkbUseExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48A06A8: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 128 bytes in 1 blocks are still reachable in loss record 31 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489C99E: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x49B6820: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 128 bytes in 1 blocks are still reachable in loss record 32 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489C99E: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x49B6820: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B650A: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69C8: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 136 bytes in 1 blocks are still reachable in loss record 33 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x404E9F: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 136 bytes in 1 blocks are still reachable in loss record 34 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B50C3: XShmCreateImage (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x405596: mlx_int_new_xshm_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x405892: mlx_new_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4037B0: init_mlx (init.c:46)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 148 bytes in 1 blocks are still reachable in loss record 35 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A0710: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 152 bytes in 1 blocks are still reachable in loss record 36 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x490640E: XkbUseExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48A06A8: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 160 bytes in 1 blocks are still reachable in loss record 37 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x488E9EF: XCreateGC (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48A05A4: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 160 bytes in 1 blocks are still reachable in loss record 38 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x488E9EF: XCreateGC (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x4050EE: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 168 bytes in 1 blocks are still reachable in loss record 39 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A00B2: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 208 bytes in 1 blocks are still reachable in loss record 40 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x49B4AE9: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49B69DF: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x49BB9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==145707==    by 0x404CF3: mlx_int_deal_shm (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x404F71: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 208 bytes in 1 blocks are still reachable in loss record 41 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B1FAE: _XEnq (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4BB6: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B5EC0: _XReadEvents (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B6205: XWindowEvent (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405405: mlx_int_wait_first_expose (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40512D: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 256 bytes in 1 blocks are still reachable in loss record 42 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x490355D: XkbAllocClientMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE0DE: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 352 bytes in 7 blocks are still reachable in loss record 43 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FD8F5: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 416 bytes in 2 blocks are still reachable in loss record 44 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B1FAE: _XEnq (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4BB6: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B5EC0: _XReadEvents (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B61D0: XWindowEvent (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405405: mlx_int_wait_first_expose (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40512D: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 468 bytes in 209 blocks are definitely lost in loss record 45 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x403D65: ft_split (ft_split.c:38)
==145707==    by 0x402D3C: set_points (parse.c:96)
==145707==    by 0x4038D4: init_raw (init.c:70)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 512 bytes in 1 blocks are still reachable in loss record 46 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489B46A: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489B84E: XInternAtom (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404F4B: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 570 bytes in 10 blocks are definitely lost in loss record 47 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x404B15: gnl_calloc (get_next_line_utils.c:100)
==145707==    by 0x40473C: gnl_line (get_next_line.c:72)
==145707==    by 0x404536: get_next_line (get_next_line.c:27)
==145707==    by 0x403819: init_raw (init.c:59)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 616 bytes in 11 blocks are definitely lost in loss record 48 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x403D65: ft_split (ft_split.c:38)
==145707==    by 0x403851: init_raw (init.c:64)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 832 bytes in 4 blocks are still reachable in loss record 49 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B1FAE: _XEnq (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4BB6: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4C69: _XEventsQueued (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x488F87D: XFlush (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405707: mlx_int_new_xshm_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x405892: mlx_new_image (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4037B0: init_mlx (init.c:46)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 936 bytes in 1 blocks are still reachable in loss record 50 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x405050: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 1,120 bytes in 1 blocks are still reachable in loss record 51 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4903619: XkbAllocClientMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FDEB7: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 1,456 bytes in 7 blocks are still reachable in loss record 52 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B1FAE: _XEnq (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4BB6: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B5F01: _XReadEvents (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B61D0: XWindowEvent (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405405: mlx_int_wait_first_expose (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40512D: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 2,028 bytes in 27 blocks are still reachable in loss record 53 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FD7DD: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 2,048 bytes in 1 blocks are still reachable in loss record 54 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FD914: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 2,496 bytes in 12 blocks are still reachable in loss record 55 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48B1FAE: _XEnq (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B4BB6: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B5F01: _XReadEvents (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48B6205: XWindowEvent (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405405: mlx_int_wait_first_expose (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40512D: mlx_new_window (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403791: init_mlx (init.c:45)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 3,650 bytes in 10 blocks are definitely lost in loss record 56 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x403BBC: ft_strjoin (ft_strjoin.c:26)
==145707==    by 0x40383A: init_raw (init.c:62)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 4,096 bytes in 1 blocks are still reachable in loss record 57 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48FE13E: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE41E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE4F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x48FE8AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x405C67: mlx_int_param_KeyRelease (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x4052B5: mlx_loop (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x40260C: main (fdf.c:55)
==145707== 
==145707== 4,704 bytes in 1 blocks are still reachable in loss record 58 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489FB31: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 5,016 bytes in 11 blocks are still reachable in loss record 59 of 63
==145707==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4028D6: meta_segments (parse.c:49)
==145707==    by 0x402DA7: set_points (parse.c:99)
==145707==    by 0x4038D4: init_raw (init.c:70)
==145707==    by 0x40256F: main (fdf.c:47)
==145707== 
==145707== 14,612 bytes in 1 blocks are still reachable in loss record 60 of 63
==145707==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4CE64FB: xcb_connect_to_fd (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE6E6B: xcb_connect_to_display_with_auth_info (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x48AFEE9: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 16,384 bytes in 1 blocks are still reachable in loss record 61 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x489FEBE: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 21,168 bytes in 1 blocks are still reachable in loss record 62 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x4CE6204: xcb_connect_to_fd (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x4CE6E6B: xcb_connect_to_display_with_auth_info (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==145707==    by 0x48AFEE9: _XConnectXCB (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x489FB68: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== 33,600 bytes in 2 blocks are still reachable in loss record 63 of 63
==145707==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==145707==    by 0x48A0290: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==145707==    by 0x404EB7: mlx_init (in /home/akjoerse/42/999_GitHub/42006/repo/actual/fdf)
==145707==    by 0x403768: init_mlx (init.c:44)
==145707==    by 0x40257B: main (fdf.c:48)
==145707== 
==145707== LEAK SUMMARY:
==145707==    definitely lost: 5,361 bytes in 241 blocks
==145707==    indirectly lost: 0 bytes in 0 blocks
==145707==      possibly lost: 0 bytes in 0 blocks
==145707==    still reachable: 115,168 bytes in 122 blocks
==145707==         suppressed: 0 bytes in 0 blocks
==145707== 
==145707== For lists of detected and suppressed errors, rerun with: -s
==145707== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 1 from 1)
-->	
