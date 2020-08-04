import re
from collections import defaultdict
from llist import dllist, dllistnode
import random
import sys

class dps_ARM(object):
    def __init__(self, R0=0, R1=0, R2=0, R3=0, R4=0, R5=0, R6=0, R7=0, R8=0, R9=0, R10=0, R11=0, R12=0, R13=0, R14=0, R15=0):
        self.R0 = R0
        self.R1 = R1
        self.R2 = R2
        self.R3 = R3
        self.R4 = R4
        self.R5 = R5
        self.R6 = R6
        self.R7 = R7
        self.R8 = R8
        self.R9 = R9
        self.R10 = R10
        self.R11 = R11
        self.R12 = R12
        
        # Stack pointer
        self.R13 = R13

        # Link Register
        self.R14 = R14

        # Program counter (PC)
        self.R15 = R15

        self.in_use = set()
        self.free = {"R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12"}
        self.mapping = defaultdict(int)
        self.data = defaultdict(str)

    def __in_use__(self):
        return self.in_use
    
    def __check_register__(self, value):
        return self.mapping[value]

    def __allocate__(self, value):
        try:
            target_register = random.sample(self.free, 1)[0]
            self.free.remove(target_register)
            self.in_use.add(target_register)
            register_number = int(target_register.split("R")[1])
            self.mapping[value] = register_number

            return register_number
        except:
            print("Ran out of registers....")
            exit()

    def __free__(self):
        return self.free

    def __release__(self, argument=0):
        try:
            self.in_use.remove(argument)
            self.free.add(argument)
        except:
            pass
    
    def __add_data__(self, vector_name, vector_value):
        self.data[vector_name] = vector_value
    
    def __obtain_data__(self):
        return self.data

    def update_R0(self, R0=0):
        self.R0 = R0

    def update_R1(self, R1=0):
        self.R1 = R1

    def update_R2(self, R2=0):
        self.R2 = R2

    def update_R3(self, R3=0):
        self.R3 = R3

    def update_R4(self, R4=0):
        self.R4 = R4

    def update_R5(self, R5=0):
        self.R5 = R5

    def update_R6(self, R6=0):
        self.R6 = R6

    def update_R7(self, R7=0):
        self.R7 = R7

    def update_R8(self, R8=0):
        self.R8 = R8

    def update_R9(self, R9=0):
        self.R9 = R9

    def update_R10(self, R10=0):
        self.R10 = R10

    def update_R11(self, R11=0):
        self.R11 = R11

    def update_R12(self, R12=0):
        self.R12 = R12

    def update_R13(self, R13=0):
        self.R13 = R13

    def update_R14(self, R14=0):
        self.R14 = R14

    def update_R15(self, R15=0):
        self.R15 = R15

class node_value(object):
    def __init__(self, op="", destination="", source_1="", source_2="", Label=""):
        self.op = op
        self.destination = destination
        self.source_1 = source_1
        self.source_2 = source_2
        self.Label = Label
        
    def __print__(self):
        print(
            '{:<10}'.format(self.Label),
            '{:<6}'.format(self.op),
            '{:<6}'.format(self.destination),
            '{:<6}'.format(self.source_1),
            '{:<6}'.format(self.source_2)
        )
        # print(self.Label, self.op, self.destination, self.source_1, self.source_2, sep="\t", end="\n")
        

    def __getvalues__(self):
        return {
            "op" : self.op,
            "destination" : self.destination,
            "source_1" : self.source_1,
            "source_2" : self.source_2,
            "Label" : self.Label
        }
    
    def __changevalues__(self,  op = None,  destination = None,  source_1 = None,  source_2 = None,  Label = None):
        if(op != None):
            self.op = op

        if(destination != None):
            self.destination = destination

        if(source_1 != None):
            self.source_1 = source_1

        if(source_2 != None):
            self.source_2 = source_2

        if(Label != None):
            self.Label = Label
            
__dps__ = dps_ARM()
tcg_code = dllist()

def dump_tcg_to_file():
    sys.stdout = open("TCG.s", "w")

    print(".TEXT")
    for value in tcg_code:
        dps_temp = value.__getvalues__()
        
        print('{:<10}'.format(dps_temp['Label']), end=" ")
        
        if dps_temp['op'] != "":
            if dps_temp['op'] == 'LDR':
                print("@", end="")
            print('{:<6}'.format(dps_temp['op']), end="")

        if dps_temp['destination'] != "":
            print('{:<6}'.format(dps_temp['destination']), end="")
        
        if dps_temp['source_1'] != "":
            print(",", end="")
            print('{:<6}'.format(dps_temp['source_1']), end="")
    
        if dps_temp['source_2'] != "":
            print(",", end="")
            print('{:<6}'.format(dps_temp['source_2']), end="")
        print()

    print("SWI 0x011")
    print("\n\n")
    print(".DATA")
    data_dict = __dps__.__obtain_data__()
    for key, value in data_dict.items():
        value_split = value.split("(")[1].split(")")[0].split(",")
        # print(value_split)
        value_print = ','.join("\""+str(p)+"\"" for p in value_split)
        print(key, ": .asciz", value_print)
    sys.stdout.close()


operators = {"+", "*", "-", "/"}
assignment = {"<-", "->", "<<-", "->>", "="}
relop = {"<", ">", "==", "!="}
assembly_op = {"ADD", "SUB", "MUL", "DIV"}

def vector_subroutine(snippet):
    __dps__.__add_data__(snippet[4], snippet[2])

def load_subroutine(variable_value, destination_value, vector=0, vector_address_store=None, offset=0, vector_name=None):
    if vector == 0:
        # temp_node = node_value(op="LDR", destination=destination_value, source_1="=["+str(variable_value)+"]", source_2="#0")
        # tcg_code.appendright(temp_node)
        # tcg_code.last.value.__print__()
        temp_node = node_value(op="LDR", destination=destination_value, source_1="["+str(variable_value)+"]")
        tcg_code.appendright(temp_node)
        tcg_code.last.value.__print__()
    else:

        temp_node = node_value(op="LDR", destination=vector_address_store, source_1="="+str(vector_name)+"")
        tcg_code.appendright(temp_node)
        tcg_code.last.value.__print__()
            
        temp_node = node_value(op="LDR", destination=destination_value, source_1="["+str(vector_address_store)+"]", source_2="#"+str(offset))
        tcg_code.appendright(temp_node)
        tcg_code.last.value.__print__()
        

def operators_subroutine(snippet):
    print("\n\nOperators_subroutine")
    temp_op = snippet[1]
    print(snippet)

    if temp_op == "+":    
        op = "ADD"
    
    elif temp_op == "-":
        op = "SUB"
    
    elif temp_op == "*":
        op = "MUL"

    elif temp_op == "/":
        op = "DIV"

    try:
        source_1_temp = __dps__.__check_register__(snippet[3])
        source_1 = "R"+str(source_1_temp)
    except:
        print("Wrong Operation")

    try:
        source_2_temp = int(snippet[2])
        source_2 = "#"+str(source_2_temp)
    except:
        source_2_temp = __dps__.__check_register__(snippet[2])
        source_2 = "R"+source_2_temp
    
    destination_temp = __dps__.__check_register__(snippet[4])
    destination = "R"+str(destination_temp)

    temp_node = node_value(op=op, destination=destination, source_1=source_1, source_2=source_2)
    tcg_code.appendright(temp_node)
    tcg_code.last.value.__print__()
    
    
def assignment_subroutine(snippet):
    print("\n\nAssignment_subroutine")
    print(snippet)
    prev_code = tcg_code.last
    mov_or_not = 1

    if prev_code != None and prev_code.value.__getvalues__()['op'] in assembly_op:
        print(prev_code.value.__getvalues__())
        if prev_code.value.__getvalues__()['destination'] == "R"+str(__dps__.__check_register__(snippet[2])) and prev_code.value.__getvalues__()['source_1'] == "R"+str(__dps__.__check_register__(snippet[4])):
            dest_temp = prev_code.value.__getvalues__()['source_1']
            prev_code.value.__changevalues__(destination=dest_temp)
            mov_or_not = 0
            tcg_code.last.value.__print__()

    if mov_or_not == 1:        
        op = "MOV"
        destination_value = __dps__.__check_register__(snippet[4])
        
        if destination_value == 0:
            destination_value = __dps__.__allocate__(snippet[4])
            load_subroutine(snippet[4], "R"+str(destination_value))
        
        destination = "R"+str(destination_value)
        
        try:
            source = int(snippet[2])
            source_1 = "#"+str(source)
        
        except:
            source = __dps__.__check_register__(snippet[2])
            
            if source == 0:
                source = __dps__.__allocate__(snippet[2])
            
            source_1 = "R"+str(source)

        temp_node = node_value(op=op, destination=destination, source_1=source_1)
        tcg_code.appendright(temp_node)
        tcg_code.last.value.__print__()
    print("\n\n")

def relop_subroutine(snippet):
    if snippet[1] == ">":
        op = "RSBS"
    else:
        op = "SUBS"

    try:
        if "[" in snippet[3] and "]" in snippet[3]:
            vector_name = snippet[3].split("[")[0]
            vector_index = int(snippet[3].split("[")[1].split("]")[0])

            check_vector_loaded = __dps__.__check_register__(str(vector_name))
            
            if check_vector_loaded == 0:
                vector_base_address = __dps__.__allocate__(str(vector_name))
            else:
                vector_base_address = check_vector_loaded

            source_1_temp = __dps__.__check_register__(str(vector_name) + "_value")
            if source_1_temp == 0:
                destination_value = __dps__.__allocate__(str(vector_name) + "_value")
                
            load_subroutine(snippet[4], "R"+str(destination_value), vector=1, vector_address_store="R"+str(vector_base_address), offset=vector_index, vector_name=vector_name)
            source_1 = "R"+str(destination_value)
        
        else:
            source_1_temp = __dps__.__check_register__(snippet[3])
            source_1 = "R"+str(source_1_temp)

    except:
        print("Wrong Operation")

    try:
        source_2_temp = int(snippet[2])
        source_2 = "#"+str(source_2_temp)
    except:
        source_2_temp = __dps__.__check_register__(snippet[2])
        source_2 = "R"+source_2_temp
    
    destination_temp = __dps__.__check_register__(snippet[4])
    destination = "R"+str(destination_temp)

    temp_node = node_value(op=op, destination=destination, source_1=source_1, source_2=source_2)
    tcg_code.appendright(temp_node)
    tcg_code.last.value.__print__()


def loop_subroutine(snippet):
    print("\n\nIF_subroutine")
    temp_node = node_value(op="BGE", destination=snippet[4])
    tcg_code.appendright(temp_node)
    tcg_code.last.value.__print__()
    

def label_subroutine(snippet):
    print("\n\nLabel_subroutine")
    temp_node = node_value(Label=str(snippet[4])+":")
    tcg_code.appendright(temp_node)
    tcg_code.last.value.__print__()

def branch_subroutine(snippet):
    print("\n\nBranch_subroutine")
    temp_node = node_value(op="B", destination=snippet[4])
    tcg_code.appendright(temp_node)
    tcg_code.last.value.__print__()

ip_file = open("./opt_for_tcg.txt", "r") 
lines = ip_file.readlines() 

for line in lines:
    snippet = line.strip().split("\t")
    
    if snippet[1] in operators:
        operators_subroutine(snippet)
    
    elif snippet[1] in assignment:
        if "c(" in snippet[2]:
            vector_subroutine(snippet)
        else:
            assignment_subroutine(snippet)
        
    elif snippet[1] in relop:
        relop_subroutine(snippet)

    elif snippet[1] == 'not':
        pass

    elif snippet[1] == 'if':
        loop_subroutine(snippet)
        
    elif snippet[1] == "Label":
        label_subroutine(snippet)

    elif snippet[1] == "goto":
        branch_subroutine(snippet)

    else:
        print(snippet)

print(__dps__.__free__())
dump_tcg_to_file()
