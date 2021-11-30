function microdaq_setup()

cd microdaq;
curpath = pwd;
tgtpath = curpath(1:end-length('/microdaq'));
addpath(fullfile(tgtpath, 'microdaq'));
addpath(fullfile(tgtpath, 'demos'));
addpath(fullfile(tgtpath, 'blocks'));
addpath(fullfile(tgtpath, 'microdaq','ext_mode'));
addpath(fullfile(tgtpath, 'tools'));
% addpath(fullfile(tgtpath, 'help'));
savepath;
if ispref('microdaq')
	rmpref('microdaq');
end
addpref('microdaq','TargetRoot',fix_slash(curpath));
[CompilerRoot] = ccs_setup_paths;
addpref('microdaq','CompilerRoot',CompilerRoot);

% Ask for Target IP
tip = inputdlg('Enter MicroDAQ IP address:','MicroDAQ IP Address',1,{'10.10.1.1'});
ipAddr = regexp(tip{1}, '((0*(1\d\d|2[0-4]\d|25[0-4]|\d\d|\d)\.){3}0*(1\d\d|2[0-4]\d|25[0-4]|\d\d|\d))', 'match');
if isempty(ipAddr)
    error('Wrong IP address format!'); 
end

addpref('microdaq','TargetIP',tip{1});

% Generate blocks
disp('<strong>Generating blocks for MicroDAQ</strong>'); 
cd('../blocks');
lct_genblocks;
cd(curpath);

% Register toolchain
microdaq_tc_refresh;

% Run XDC Tools on SYS/BIOS configuration file
cd('sysbios/cpu2');
content = fileread( 'linker_template' ) ;
newContent = strrep( content, '||libsPath||', [getpref('microdaq','TargetRoot'),'/sysbios/cpu2/']);

linker_file_fd = fopen('configPkg/linker.cmd', 'w');
if linker_file_fd > -1
    fwrite(linker_file_fd, newContent, 'uchar');
    fclose(linker_file_fd);
end

cd(curpath);

% Generate help
%cd('../help/source');
%genhelp;
%cd(curpath);

sl_refresh_customizations;
rehash toolbox;
disp('<strong>MicroDAQ Target setup is complete!</strong>');
disp('Explore <a href="matlab:cd([getpref(''microdaq'',''TargetRoot''),''/../demos''])">demos</a> directory and access <a href="matlab:doc -classic">documentation</a>');
cd([getpref('microdaq','TargetRoot'),'/../demos']);
end

function [CompilerRoot] = ccs_setup_paths()

path = uigetdir(matlabroot,'Compiler root directory: (c6000_8.X.X)');
if path == 0 
    cd('..');
    error('Abording microdaq_setup...'); 
end
CompilerRoot = fix_slash(path);
end

function path = fix_slash(path0)
path = path0;
if ispc
	path(path=='\')='/';
end
end
