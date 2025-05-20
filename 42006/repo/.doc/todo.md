#	[README](README.md#index)  

- [ ] assign tile and zoom and offset factors
- [ ] make structure for xyz/01
	- [ ] common
		- [ ] x
			- [ ] 0
			- [ ] 1
		- [ ] z
			- [ ] 0
			- [ ] 1
	- [ ] horizontal
		- [ ] z
			- [ ] 0
			- [ ] 1
		- [ ] y
			- [ ] 0
			- [ ] 1
	- [ ] vertical
		- [ ] z
			- [ ] 0
			- [ ] 1
		- [ ] y
			- [ ] 0
			- [ ] 1

eight points:

x0	— x origin point `(0),0`  
y0	— y origin point `0,(0)`  
x1	— horizontal neighbor x `(1),0`  
y1	— horizontal neighbor y `1,(0)`  
y2	— vertical neighbor y `0,(1)`  
z0	— height at `(0,0)`  
z1	— height at `(0,1)`  
z2	— height at `(1,0)`  


abcd
efgh