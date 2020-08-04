import nltk
import re
# grammar = nltk.CFG.fromstring("""
    
#   """)

# ------------------------------------------------------
# sr = nltk.parse.ShiftReduceParser(grammar)
# sentence1 = 'abcezxc = 2345'.split()
# for t in sr.parse(sentence1):
#     print(t)
# ------------------------------------------------------


# ------------------------------------------------------
# sentence = 'abcezxc = 2345'.split()
# def parse(sent):
#     #Returns nltk.Tree.Tree format output
#     a = []  
#     parser = nltk.ChartParser(grammar)
#     for tree in parser.parse(sent):
#         a.append(tree)
#     return(a[0]) 

# #Gives output as structured tree   
# print(parse(sentence))

# #Gives tree diagrem in tkinter window
# parse(sentence).draw()
# ---------------------------------------------------------

grammar = nltk.data.load('sample_grammar3.cfg')
print(grammar)
# sentences = nltk.data.load('sample.txt')
# sentences = nltk.parse.util.extract_test_sentences(sentences)
# print(sentences)
# testsentence = sentences[0]
# print(testsentence[0])
# sentence = testsentence[0]


def parse(sent):
    #Returns nltk.Tree.Tree format output
    a = []  
    parser = nltk.parse.BottomUpChartParser(grammar)
    print (list(parser.parse(sent)))
    for tree in parser.parse(sent):
        a.append(tree)
    return(a[0]) 

# sentence = r'abcezxc <- 2345 \n defg <- 123 \n expression1 <- 1 + 2 + 3 + 4 + 5 \n'.split()
sentence = r'for ( i in seq ( 1 , 6 ) ) \n { \n expression1 = expression1 + 1 \n } \n'.split()
print(sentence)
parse(sentence).draw()

# chart = parser.chart_parse(sentence)
# print((chart.num_edges()))
# chart.draw()