import nltk

def parse(sent):
    capture_tree = []  
    parser = nltk.parse.BottomUpChartParser(grammar)
    print (list(parser.parse(sent)))
    for tree in parser.parse(sent):
        capture_tree.append(tree)
    return(capture_tree[0]) 

grammar = nltk.data.load('sample_grammar3.cfg')
# print(grammar)

while True:
    print("Please select your option: - ")
    print("1. Parse tree for For loop")
    print("2. Parse tree for Repeat loop")
    print("3. Parse tree for While loop")
    print("4. Parse tree for Variable declaration")
    print("5. Parse tree for Vector declaration")
    print("6. Exit")
    
    correct_option = 0
    try:
        option = int(input("Choice Number: -$"))
    except:
        print("Please re-enter correctly")
        continue
    
    if option == 1:
        for_file = open("for_loop.r", 'r')
        raw_sentence = for_file.read()
        for_file.close()
        correct_option = 1
    
    elif option == 2:
        repeat_file = open("repeat_loop.r", 'r')
        raw_sentence = repeat_file.read()
        repeat_file.close()
        correct_option = 1
    
    elif option == 3:
        while_file = open("while_loop.r", 'r')
        raw_sentence = while_file.read()
        while_file.close()
        correct_option = 1
    
    elif option == 4:
        variable_file = open("variable_declr.r", 'r')
        raw_sentence = variable_file.read()
        variable_file.close()
        correct_option = 1
    
    elif option == 5:
        vector_file = open("vector_declr.r", 'r')
        raw_sentence = vector_file.read()
        vector_file.close()
        correct_option = 1

    elif option == 6:
        break
    
    if correct_option == 1:
        processed_sentence = repr(raw_sentence).replace("\\n", " \\n ").replace("\'","").replace("\"","").split()
        print(raw_sentence)
        print(processed_sentence)
        parse(processed_sentence).draw()
        print("\n"*3)


# sentence = r'for ( i in seq ( 1 , 6 ) ) \n { \n expression1 = expression1 + 1 \n } \n'.split()
# print(sentence)
# parse(sentence).draw()