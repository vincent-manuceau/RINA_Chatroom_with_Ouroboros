irm ipcp bootstrap type eth-llc name llc layer eth dev br0
irm ipcp enroll name normal_1 layer normal_layer autobind
irm n r normal_layer l eth
irm n r normal_1 l eth
#irm ipcp connect name normal_0 dst normal_1 comp mgmt
#irm ipcp connect name normal_0 dst normal_1 comp dt
