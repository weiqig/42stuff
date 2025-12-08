#method taken from forum
#cat /sys/class/net/*/address

#using ifconfig to get available MAC addresses
#grep to specify which ip address to look at
#awk to retrieve the second variable of the outputs 
ifconfig | grep ether | awk '{print $2}'
