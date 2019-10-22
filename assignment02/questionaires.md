1. 
a) the value goes from `2147483647` to `-2147483648`
b) the value goes from `0x7FFFFFFF` to `0x80000000`
c) both `N` and `V` flags are set in ASPR, because the previous execution produced a negative number and was an overflowed operation

2. 
a) the value goes from `-1` to `0`
b) neither `N` nor `V` flags are set, since -1+1=0, its result is not negative, and overflow only happens when max_int+1 or min_int-1 not when going from negative to zero

3. 
a) the value goes from `2147483647` to `2147483648`
b) both `N` and `V` flags are set in ASPR, I think the reason that we have the same result as (1) is because the assembly code/ the cpu does not care about the number sign, in the end their hex/register value both goes from `0x7FFFFFFF` to `0x80000000`, the only difference is that how C interprets them

4. 
a) the value goes from `4294967295` to `0`
b) same as (2) since it is the same operation in the eyes of the cpu, so neither `N` nor `V` were set

5. 
a) the scope of the "counter" is the entire file
b) it's no longer visible in the "locals"
c) we can track it in the "statics" view
d) `&counter == 0x20000000`

6. 
a) `counter == 4`
b) we manipulated the counter value throw a pointer to its address: 
`&counter == p_int == 0x20000000` hence `++(*p_int) == count++`

7. 
a) `&counter == 0x20000000` 
b) counter is stored in RAM
c) `counter == 4`