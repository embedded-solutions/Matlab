function result = mdaqOpen()
% MLink library name
TargetRoot = getpref('microdaq','TargetRoot');
if ispc
    arch = computer('arch');
    suffix = arch(end-1:end);
    mlinklib = ['MLink',suffix];
else
    mlinklib = 'libmlink64';
end

% if libisloaded(mlinklib)
%     unloadlibrary(mlinklib); 
% end

if ~libisloaded(mlinklib)
    loadlibrary([TargetRoot,'/MLink/',mlinklib],[TargetRoot,'/MLink/MLink.h']);
end

link_fd = libpointer('int32Ptr',0);
TargetIP = getpref('microdaq','TargetIP');
result = calllib(mlinklib,'mlink_connect',TargetIP,4343,link_fd);
if result < 0
    calllib(mlinklib,'mlink_disconnect_all');
    result = calllib(mlinklib,'mlink_connect',TargetIP,4343,link_fd);
    if result < 0
        error(calllib(mlinklib,'mlink_error',result));
    end
end

