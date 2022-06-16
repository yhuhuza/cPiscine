#!/bin/bash
ifconfig -a | grep "ether " | awk '{$1= ""; print $0}' 
