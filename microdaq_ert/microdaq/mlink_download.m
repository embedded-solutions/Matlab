function mlink_download(outfile,TargetRoot,upload)
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

result = mdaqOpen();
if result < 0
    error(calllib(mlinklib,'mlink_error',result));
end
link_fd = libpointer('int32Ptr',result);

% Upload DSP binary to MicroDAQ
if upload == 1
    msgbox('Uploading to supported!','Alert');
else

    % Load DSP binary to MicroDAQ
    disp('### Loading DSP binary to MicroDAQ...');
	disp(outfile);
    result = calllib(mlinklib,'mlink_dsp_init',link_fd.Value,outfile, 100, 10);
    if result < 0
        out = calllib(mlinklib,'mlink_error',result);
        error('Error loading binary to MicroDAQ: %s',out);
    end
    % Start DSP binary on MicroDAQ
    disp('### Starting DSP binary on MicroDAQ...');
    result = calllib(mlinklib,'mlink_dsp_start',link_fd.Value);
    if result < 0
        out = calllib(mlinklib,'mlink_error',result);
        error('Error starting binary on MicroDAQ: %s',out);
    end
    
    mdaqClose();
end