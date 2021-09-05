if [[  $1 ]]
then
#	echo `ip -o -4 addr list $1 | awk -F ' *|/' '{print $4}'`
  irm ipcp bootstrap type eth-llc name llc layer eth dev $1
	irm ipcp enroll name normal_1 layer normal_layer autobind
	irm n r normal_layer l eth
	irm n r normal_1 l eth  
else
  echo "Usage : set your interface name as argument (br0, enp3s0, eth0, ...)"
fi

#irm ipcp connect name normal_0 dst normal_1 comp mgmt
#irm ipcp connect name normal_0 dst normal_1 comp dt
