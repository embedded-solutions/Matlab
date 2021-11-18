message = canMessage (4,false,8);
message.Data = ([0 0 0 0 0 0 0 0]);
canch1 = canChannel('Vector','VN1640 1',1);
start(canch1)
transmit(canch1,message)