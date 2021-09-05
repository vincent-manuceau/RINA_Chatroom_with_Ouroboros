if [[  $1 ]]
then
#	echo `ip -o -4 addr list $1 | awk -F ' *|/' '{print $4}'`
  irm ipcp bootstrap type udp ip `ip -o -4 addr list $1 | awk -F ' *|/' '{print $4}'` name udp layer udp dev $1  
else
  echo "Usage : set your interface name as argument (br0, enp3s0, eth0, ...)"
fi

