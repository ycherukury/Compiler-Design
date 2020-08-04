.TEXT
           @LDR  R10   ,[expression1]
           MOV   R10   ,#15   
           @LDR  R8    ,=defg 
           @LDR  R11   ,[R8 ,#0]
           MOV   R11   ,#20   
           @STR  R11   ,[R8 ,#0]
           @LDR  R1    ,[i]   
           MOV   R1    ,#1    
For_0:     
           @LDR  R3    ,[t4]  
           SUBS  R3    ,R1    ,#6    
           BGE   For_1 
           ADD   R1    ,R1    ,#1    
           ADD   R10   ,R10   ,#1    
           B     For_0 
For_1:     
           @LDR  R2    ,[testvar]
           MOV   R2    ,#10   
While_0:   
           @LDR  R9    ,[t8]  
           RSBS  R9    ,R2    ,#2    
           BGE   While_1
           SUB   R2    ,R2    ,#1    
           B     While_0
While_1:   
           @LDR  R4    ,[count]
           MOV   R4    ,#1    
Repeat_0:  
           @LDR  R7    ,[t11] 
           RSBS  R7    ,R4    ,#3    
           BGE   Loop_1
           B     Repeat_1
           B     Loop_2
Loop_1:    
           ADD   R4    ,R4    ,#2    
Loop_2:    
           B     Repeat_0
Repeat_1:  
           @LDR  R8    ,=defg 
           @LDR  R11   ,[R8 ,#0]
           @LDR  R12   ,[t14] 
           SUBS  R12   ,R11   ,#8    
           BGE   Loop_3
           B     Loop_4
Loop_3:    
Loop_4:    
           @LDR  R6    ,[b]   
           MOV   R6    ,#5    
           @STR  R1    ,[i]   
           @LDR  R1    ,[t16] 
           SUBS  R1    ,R6    ,#8    
           BGE   Loop_5
           B     Loop_6
Loop_5:    
Loop_6:    
           @STR  R4    ,[count]
           @LDR  R4    ,[c]   
           MOV   R4    ,#5    
           @STR  R3    ,[t4]  
           @LDR  R3    ,[t18] 
           SUBS  R3    ,R4    ,#8    
           BGE   Loop_7
           B     Loop_8
Loop_7:    
Loop_8:    
SWI 0x011



.DATA
defg : .asciz "1","2","3","4","5","6","'abcdefg'","'how'"
