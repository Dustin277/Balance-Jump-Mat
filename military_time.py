# -*- coding: utf-8 -*-
"""
Created on Thu Apr 30 16:06:17 2020

@author: syate
"""
from datetime import datetime


def military_time(time):
  if time[-2:] == 'AM' and time[:2] == '12':
      return '00' + time[2:-2]
  elif time[-2:] == 'AM':
      return time[:2]
  elif time[-2:] == 'PM' and time[:2] == '12':
      return time[:-2]
  else:
      return str(int(time[:2]) + 12) + time[2:8] 

def main():
    now = datetime.now()
    current_time = now.strftime('%H:%M:%S')
    
    print(military_time(current_time))
    
main()