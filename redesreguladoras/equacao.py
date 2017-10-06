#-*- coding: utf-8 -*-
#! /usr/bin/python

from __future__ import print_function
from random import randint

arquivo = open('equation2.txt', 'r')
lines = arquivo.readlines()
arquivo.close()

# vect os nomes de cada no
vect = []
for i in lines:
    val = i.split('(')[0]
    vect.append(val)

# value o tamanho de cada equacao
# equation as operacoes indicando a posicao do vertice
value = [randint(-1,1) for i in range(96)]
value[6] = 1
value[7] =1

equation = [[] for i in range(96)]

for i in range(6):
    equation[i].append(value[i]*100)
equation[6].append(100)
equation[7].append(100)

cant = 0
for i in range(8,len(vect)):
    temp = lines[i].split('sgn[')[1]
    cant += len(temp.split(' '))
    # value.append(len(temp.split(' ')))
    signal = temp.split(' ')
    print (signal, end='    ')
    print (len(temp.split(' ')))
    for j in signal:
        oper = j.split('(')[0]
        print (oper)
        try:
            number = int(oper[1])
            if oper[0] == '-':
                number = number *(-1)
            equation[i].append(number*100)
        except:
            if oper[0] == '+':
                print(vect.index(oper[1:]))
                equation[i].append(vect.index(oper[1:]))
            else:
                print ((vect.index(oper[1:])*-1))
                equation[i].append((vect.index(oper[1:])*-1))
    #     print ('letra')
    # print (signal)
    # print (temp.split(' '))
    # print (len(temp.split(' ')))
# print (len(equation), "    ", cant)
# print ('equation = ',equation)
print(' ************************************* ')
print (equation)
# print (len(equation))
for i in range(len(equation)):
    # print(len(equation[i]))
    for j in range(len(equation[i])):
        txt = "equation["+str(i)+"]["+str(j)+"]="+str(equation[i][j])+';'
        print(txt)
    #     if j == 0:
    #         txt += str(equation[i][j])
    #     else:
    #         txt +=', '+str(equation[i][j])
    #
    # txt += '};'

print("****************************************************")
txt1 = ""
txt1 = "char vect={"
for i in range(len(vect)):
    if i == 0:
        txt1 += '\"'+str(vect[i])+'\"'
    else:
        txt1 +=', \"'+str(vect[i])+'\"'

txt1 += '};'
print (txt1)

print("*********************************************")
txt1 = ""
txt1 = "int value={"
for i in range(len(value)):
    if i == 0:
        txt1 += str(value[i])
    else:
        txt1 +=', '+str(value[i])

txt1 += '};'
print (txt1)
print("*********************************************")
txt = ""
n = (int(input("Que equacao está procurando?: "))-1)
print (value[n])
for i in range(len(equation[n])):
    if int(equation[n][i])>0:
        if equation[n][i] >= 100:
            txt+="+"+str(equation[n][i]/100)
        else:
            txt+="+"+str(vect[equation[n][i]])
    else:
        if equation[n][i] <= -100:
            txt+=str(equation[n][i]/100)
        else:
            txt+="-"+str(vect[(equation[n][i])*-1])
print (txt)

#print ('val = ', value)
