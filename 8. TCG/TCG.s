.TEXT
           @LDR   R11   ,[expression1]
           MOV   R11   ,#15   
           @LDR   R6    ,[i]   
           MOV   R6    ,#1    
For_0:     
           SUBS  R0    ,R6    ,#6    
           BGE   For_1 
           ADD   R6    ,R6    ,#1    
           ADD   R11   ,R11   ,#1    
           B     For_0 
For_1:     
           @LDR   R1    ,[testvar]
           MOV   R1    ,#10   
While_0:   
           RSBS  R0    ,R1    ,#2    
           BGE   While_1
           SUB   R1    ,R1    ,#1    
           B     While_0
While_1:   
           @LDR   R10   ,[count]
           MOV   R10   ,#1    
Repeat_0:  
           RSBS  R0    ,R10   ,#3    
           BGE   Loop_1
           B     Repeat_1
           B     Loop_2
Loop_1:    
           ADD   R10   ,R10   ,#2    
Loop_2:    
           B     Repeat_0
Repeat_1:  
           @LDR   R9    ,=defg 
           @LDR   R2    ,[R9]  ,#1    
           SUBS  R0    ,R2    ,#8    
           BGE   Loop_3
           B     Loop_4
Loop_3:    
Loop_4:    
SWI 0x011



.DATA
defg : .asciz "1","2","3","4","5","6","'abcdefg'","'how'"
