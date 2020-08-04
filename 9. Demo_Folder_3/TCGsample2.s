/*Given number is present in array or not*/

.TEXT
ldr r0, =a
ldr r6, [r0, #16]
mov r1, #0
str r1, [r0, #4]
swi 0x011

.DATA
a: .word 10, 20, 30, 40, 50, 60
