1.  
b `MOV R3 #1`, `STR R3, [R0]`  
c `LDR R4 [R1]`, `ORR.W R4 R4 #32`, `STR R4 [R1]`  
2. 
a For a function that takes in 5 integers, the first 4 are stored in register R0,R1,R2,R3 whereas the 5th is put onto the stack
b `PUSH {R1-R7, LR}`
c `PUSH {R4}`, `LDR R4, [SP, #0x4]` since we have the first 4 arguments in R0-R3, compiler load the last argument from stack to R4
d Before loading the 5th argument to R4, we pushed the original R4 on to the stack, this complies to the AAPCS
