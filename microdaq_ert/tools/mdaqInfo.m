function mdaqInfo()

mdaqVer = "1.0.2";

fprintf('MicroDAQ Embedded Coder target version: %s\n',mdaqVer); 
TargetIP = getpref('microdaq','TargetIP');
fprintf('MicroDAQ IP address: %s\n',TargetIP); 


