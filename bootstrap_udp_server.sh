if [[  $1 ]]
then
#	echo `ip -o -4 addr list $1 | awk -F ' *|/' '{print $4}'`
  irm ipcp bootstrap type eth-llc name llc layer eth dev $1
	irm ipcp bootstrap type unicast name normal_0 layer normal_layer
	irm ipcp bootstrap type udp ip `ip -o -4 addr list $1 | awk -F ' *|/' '{print $4}'` name udp layer udp dev $1
	irm bind ipcp normal_0 name normal_0
	irm b i normal_0 n normal_layer
	irm name register normal_layer layer eth
	irm n r normal_0 l eth
	irm name register normal_layer layer udp
	irm n r normal_0 l udp 
else
  echo "Usage : set your interface name as argument (br0, enp3s0, eth0, ...)"
fi


