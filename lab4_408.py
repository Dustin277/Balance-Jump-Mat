# -*- coding: utf-8 -*-
"""
Created on Thu Apr 30 16:44:58 2020

@author: Bryan Soriano
"""
#re is a Regular expression operations library 
import re

def passcheck(password):
    if len(password) < 7:
        print("ERROR: password is too weak")
        print("A password is considered good if it contains") 
        print("at least 7 characters and 2 of those are a number and special")
        print("character(1-8, i.e. !@#$%^&*).")
    elif not re.search("[0-9]",password):# checks for 0-9
        print("ERROR: password is too weak")
        print("A password is considered good if it contains") 
        print("at least 7 characters and 2 of those are a number and special")
        print("character(1-8, i.e. !@#$%^&*).")
    elif not re.search("[!@#$%^&*]",password):#checks for special char
        print("ERROR: password is too weak")
        print("A password is considered good if it contains") 
        print("at least 7 characters and 2 of those are a number and special")
        print("character(1-8, i.e. !@#$%^&*).")
    else:
        return True
    
                         
print("Input a password")
while True:
    password = input()
    passcheck(password)
    if passcheck(password) == True:
        print("password accepted")
        break