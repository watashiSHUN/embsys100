    PUBLIC swapCharsAsm

    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB

/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Takes two char pointers as input and swap their underlining
                  data, return 0 if two chars are identical
C Prototype     : int swapCharsAsm(charPtr1, charPtr2)
Parameters      : R0: Address of charPtr1
                  R1: Address of charPtr2
Return value    : R0
*******************************************************************************/  

swapCharsAsm
    PUSH {R4,R5}        // peserve callers R4,R5
    LDRB R4, [R0]       // read *charPtr1 => R4
    LDRB R5, [R1]       // read *charPtr2 => R5
    STRB R5, [R0]       // store *charPtr1 = R5
    STRB R4, [R1]       // store *charPtr2 = R4
    CMP R4, R5          // compare R4 R5, the two char
    POP {R4,R5}         // restore callers R4,R5
    BEQ z               // R4 == R5??? two chars equals
    MOV R0, #1          // if not return 1
    BX LR
z   MOV R0, #0          // else return 0
    BX LR
    END