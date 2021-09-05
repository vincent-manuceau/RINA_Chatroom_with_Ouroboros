# Recursive_InternetWork_Chatroom_with_Ouroboros
About a RINA Chatroom based upon [Ouroboros](https://ouroboros.rocks) implementation

###### Work in progres !!!

-> Assuming server and clients are linked over Ethernet
-> Assuming ethernet card name is br0 for server / clients

```
 gcc -louroboros-dev -pthread client.c -o ochat_client
 gcc -louroboros-dev -pthread server.c -o ochat_server
```



## Ouroboros over Ethernet version :
```
- Server side :
./bootstrap_server.sh br0

- Client side : 
./bootstrap_client.sh br0

- Server side :
./connect.sh
./ochat_server

- Client side :
./ochat_client
```

## Ouroboros over UDP version :
```
- Server side :
./bootstrap_udp_server.sh br0

- Client side :
./bootstrap_udp_client.sh br0

- Server side :
./connect.sh
./ochat_server

- Client side :
./ochat_client
```



Made with love with [Ouroboros](https://ouroboros.rocks)
