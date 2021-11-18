% This function Stops dsp execution
function mdaqDspStop()

% MLink library name
if ispc
    arch = computer('arch');
    suffix = arch(end-1:end);
    mlinklib = ['MLink',suffix];
else
    mlinklib = 'libmlink64';
end

% Load MLink library
TargetRoot = getpref('microdaq','TargetRoot');
    if ~libisloaded(mlinklib)
        loadlibrary([TargetRoot,'/MLink/',mlinklib],[TargetRoot,'/MLink/MLink.h']);
    end

%libfunctionsview mlinklib
% Pointer to link fd
hwid = libpointer('int32Ptr',zeros(1,5));
% Connect to MicroDAQ
TargetIP = getpref('microdaq','TargetIP');
try 
    link_fd = mdaqOpen();
catch
    error('Error during connecting to MicroDAQ device');
end

result = calllib(mlinklib,'mlink_dsp_stop',link_fd);
if result < 0
    out = calllib(mlinklib,'mlink_error',result);
    result = calllib(mlinklib,'mlink_disconnect',link_fd);
    if result < 0
        out = calllib(mlinklib,'mlink_error',result);
        error('Error during disconnecting: %s',out);
    end
    error('%s',out);
end

mdaqClose();

 

