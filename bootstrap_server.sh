irm ipcp bootstrap type eth-llc name llc layer eth dev br0
irm ipcp bootstrap type unicast name normal_0 layer normal_layer
irm bind ipcp normal_0 name normal_0
irm b i normal_0 n normal_layer
irm name register normal_layer layer eth
irm n r normal_0 l eth
