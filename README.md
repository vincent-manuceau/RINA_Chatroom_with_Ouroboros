# Recursive_InternetWork_Chatroom_with_Ouroboros
About a RINA Chatroom based upon [Ouroboros](https://ouroboros.rocks) implementation

###### Work in progres !!!

-> Assuming server and clients are linked over Ethernet
-> Assuming ethernet card name is br0 for server / clients

```
 gcc -louroboros-dev -pthread client.c -o ochat_client
 gcc -louroboros-dev -pthread server.c -o ochat_server


Server side :
./bootstrap_server.sh


Client side : 
./bootstrap_client.sh


Server side :
./connect.sh
./ochat_server


Client side :
./ochat_client
```

Made with love with [Ouroboros](https://ouroboros.rocks)
