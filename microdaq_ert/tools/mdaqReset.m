function mdaqReset()

TargetIP = getpref('microdaq','TargetIP');
disp(TargetIP)
urlread(['http://' TargetIP  '/api/reboot.php'])